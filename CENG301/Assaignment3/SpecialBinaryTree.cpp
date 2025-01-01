// SpecialBinaryTree.cpp
#include "SpecialBinaryTree.h"
#include "BinaryTreeNode.h"
#include <climits>
#include <iostream>
#include <stack>

using namespace std;

SpecialBinaryTree::SpecialBinaryTree()
{
    root = nullptr;
}
SpecialBinaryTree::~SpecialBinaryTree()
{
    delete root;
}
BinaryTreeNode* SpecialBinaryTree::find_node(BinaryTreeNode* root, int value) {
    if (root == nullptr) {
        return nullptr;
    }

    if (root->get_value() == value) {
        return root;
    }

    BinaryTreeNode* found_node = find_node(root->get_left(), value);
    if (found_node != nullptr) {
        return found_node;
    }

    return find_node(root->get_right(), value);
}

bool SpecialBinaryTree::add_node(int new_value, int parent_value, bool is_left_child, bool is_right_child, bool is_root)
{
    if (is_root) {
        if (root != nullptr)
            return false;

        root = new BinaryTreeNode();
        root->set_value(new_value);
        return true;
    }
    stack<BinaryTreeNode*> nodeStack;
    nodeStack.push(root);
    while (!nodeStack.empty()) {
        BinaryTreeNode* node = nodeStack.top();
        nodeStack.pop();
        if (node->get_value() == new_value)
            return false;
        if (node->get_value() == parent_value) {
            if (is_left_child && node->get_left() != nullptr)
                return false;

            if (is_right_child && node->get_right() != nullptr)
                return false;

            BinaryTreeNode* newNode = new BinaryTreeNode();
            newNode->set_value(new_value);
            if (is_left_child)
                node->set_left(newNode);
            else
                node->set_right(newNode);

            return true;
        }
        if (node->get_left() != nullptr)
            nodeStack.push(node->get_left());
        if (node->get_right() != nullptr)
            nodeStack.push(node->get_right());
    }
    return false;
}
bool SpecialBinaryTree::update_value(int previous_value, int new_value) {
    BinaryTreeNode* node = find_node(root, previous_value);
    if (node == nullptr) {
        return false;
    }
    if (does_exist_in_subtree(root->get_value(), new_value)) {
        return false;
    }
    node->set_value(new_value);
    return true;
}



bool SpecialBinaryTree::remove_node(int value) {
    // Find the node to be removed
    BinaryTreeNode* node = find_node(root, value);
    if (node == nullptr) {
        //does not exist
        return false;
    }

    BinaryTreeNode* parent = nullptr;
    BinaryTreeNode* current = root;
    while (current != nullptr && current != node) {
        parent = current;
        if (value < current->get_value()) {
            current = current->get_left();
        } else {
            current = current->get_right();
        }
    }


    while (node->get_left() != nullptr || node->get_right() != nullptr) {
        if (node->get_left() != nullptr) {
            // Replacing left child's value
            node->set_value(node->get_left()->get_value());
            parent = node;
            node = node->get_left();
        } else {
            // Replaceing right child's value
            node->set_value(node->get_right()->get_value());
            parent = node;
            node = node->get_right();
        }
    }

    // Removing the leaf node
    if (parent != nullptr) {
        if (parent->get_left() == node) {
            parent->set_left(nullptr);
        } else {
            parent->set_right(nullptr);
        }
    } else {
        root = nullptr;
    }
    delete node;
    return true;
}



int SpecialBinaryTree::is_leaf_node(int value)
{
    BinaryTreeNode* node = find_node(root, value);
    if(node == nullptr) {
        return -1;
    }
    if(node->get_left() == nullptr && node->get_right() == nullptr) {
        return 1;
    }
    return 0;
}
bool SpecialBinaryTree::does_exist_in_subtree(int subtree_root_value, int value_to_search) {
    BinaryTreeNode* subtree_root = find_node(root, subtree_root_value);
    if (subtree_root == nullptr) {
        return false;
    }
    stack<BinaryTreeNode*> nodeStack;
    nodeStack.push(subtree_root);
    while (!nodeStack.empty()) {
        BinaryTreeNode* node = nodeStack.top();
        nodeStack.pop();
        if (node->get_value() == value_to_search) {
            return true;
        }
        if (node->get_left() != nullptr) {
            nodeStack.push(node->get_left());
        }
        if (node->get_right() != nullptr) {
            nodeStack.push(node->get_right());
        }
    }
    return false;
}

int SpecialBinaryTree::find_depth(int value) {
    // Find the node first
    BinaryTreeNode* current = find_node(root, value);
    if (current == nullptr) {
        return -1; // Node doesn't exist
    }

    return calculate_depth(root, value, 0);
}

int SpecialBinaryTree::calculate_depth(BinaryTreeNode* node, int value, int depth) {
    if (node == nullptr) {
        return -1; // if node doesn't exist
    }

    if (node->get_value() == value) {
        return depth; 
    }

    int left_depth = calculate_depth(node->get_left(), value, depth + 1);
    int right_depth = calculate_depth(node->get_right(), value, depth + 1);

    return max(left_depth, right_depth);
}


int SpecialBinaryTree::find_height(int value) {
    BinaryTreeNode* current = find_node(root, value); 
    if (current == nullptr) {
        return -1; 
    }
    
    int left_height = calculate_height(current->get_left());
    int right_height = calculate_height(current->get_right());
    
    return std::max(left_height, right_height);
}

int SpecialBinaryTree::calculate_height(BinaryTreeNode* node) {
    if (node == nullptr) {
        return 0; 
    }
    int left_height = calculate_height(node->get_left());
    int right_height = calculate_height(node->get_right());
    return 1 + std::max(left_height, right_height);
} 
void SpecialBinaryTree::preorder_traversal()
{
    if (root == nullptr) {
        cout << "There is no node in the tree. " << endl;
        return;
    }
    stack<BinaryTreeNode*> nodeStack;
    nodeStack.push(root);
    while (!nodeStack.empty()) {
        BinaryTreeNode* node = nodeStack.top();
        cout << node->get_value() << " ";
        nodeStack.pop();
        if (node->get_right())
            nodeStack.push(node->get_right());
        if (node->get_left())
            nodeStack.push(node->get_left());
    }
    cout << endl;
}
void SpecialBinaryTree::postorder_traversal()
{
    if (root == nullptr) {
        cout << "There is no node in the tree. " << endl;
        return;
    }
    stack<BinaryTreeNode*> nodeStack1, nodeStack2;
    nodeStack1.push(root);
    while (!nodeStack1.empty()) {
        BinaryTreeNode* node = nodeStack1.top();
        nodeStack1.pop();
        nodeStack2.push(node);
        if (node->get_left())
            nodeStack1.push(node->get_left());
        if (node->get_right())
            nodeStack1.push(node->get_right());
    }
    while (!nodeStack2.empty()) {
        BinaryTreeNode* node = nodeStack2.top();
        cout << node->get_value() << " ";
        nodeStack2.pop();
    }
    cout << endl;
}
void SpecialBinaryTree::inorder_traversal()
{
    if (root == nullptr) {
        cout << "There is no node in the tree. " << endl;
        return;
    }
    stack<BinaryTreeNode*> nodeStack;
    BinaryTreeNode* curr = root;
    while (curr != nullptr || !nodeStack.empty()) {
        while (curr != nullptr) {
            nodeStack.push(curr);
            curr = curr->get_left();
        }
        curr = nodeStack.top();
        nodeStack.pop();
        cout << curr->get_value() << " ";
        curr = curr->get_right();
    }
    cout << endl;
}
int SpecialBinaryTree::find_sum_of_values_in_subtree(int subtree_root_val) {
    BinaryTreeNode* subtree_root = find_node(root, subtree_root_val);
    if (subtree_root == nullptr) {
        return -1;
    }
    int sum = 0;
    stack<BinaryTreeNode*> nodeStack;
    nodeStack.push(subtree_root);
    while (!nodeStack.empty()) {
        BinaryTreeNode* node = nodeStack.top();
        nodeStack.pop();
        sum += node->get_value();
        if (node->get_left() != nullptr) {
            nodeStack.push(node->get_left());
        }
        if (node->get_right() != nullptr) {
            nodeStack.push(node->get_right());
        }
    }
    return sum;
}
int SpecialBinaryTree::find_minimum_value_in_subtree(int subtree_root_val) {
    BinaryTreeNode* subtree_root = find_node(root, subtree_root_val);
    if (subtree_root == nullptr) {
        return -1;
    }
    int min_val = INT_MAX;
    stack<BinaryTreeNode*> nodeStack;
    nodeStack.push(subtree_root);
    while (!nodeStack.empty()) {
        BinaryTreeNode* node = nodeStack.top();
        nodeStack.pop();
        min_val = min(min_val, node->get_value());
        if (node->get_left() != nullptr) {
            nodeStack.push(node->get_left());
        }
        if (node->get_right() != nullptr) {
            nodeStack.push(node->get_right());
        }
    }
    return min_val;
}

int SpecialBinaryTree::find_maximum_value_in_subtree(int subtree_root_val) {
    BinaryTreeNode* subtree_root = find_node(root, subtree_root_val);
    if (subtree_root == nullptr) {
        return -1;
    }
    int max_val = INT_MIN;
    stack<BinaryTreeNode*> nodeStack;
    nodeStack.push(subtree_root);
    while (!nodeStack.empty()) {
        BinaryTreeNode* node = nodeStack.top();
        nodeStack.pop();
        max_val = max(max_val, node->get_value());
        if (node->get_left() != nullptr) {
            nodeStack.push(node->get_left());
        }
        if (node->get_right() != nullptr) {
            nodeStack.push(node->get_right());
        }
    }
    return max_val;
}



/*
    IF YOU ADDED NEW FUNCTIONS TO SpecialBinaryTree.h IMPLEMENT THEM HERE.
    NOTE THAT, ADDING GLOBAL VARIABLES OR FUNCTIONS IS FORBIDDEN.
*/