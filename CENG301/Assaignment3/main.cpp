#include<iostream>
#include<string>
#include <climits>
#include <stack>
using namespace std;
class BinaryTreeNode
{
private:
int value;
BinaryTreeNode *left;
BinaryTreeNode *right;
public:
BinaryTreeNode();
~BinaryTreeNode();
int get_value();
void set_value(int value);
BinaryTreeNode* get_left();
void set_left(BinaryTreeNode* left);
BinaryTreeNode* get_right();
void set_right(BinaryTreeNode* right);
};
BinaryTreeNode::BinaryTreeNode()
{
    value = 0;
    left = nullptr;
    right = nullptr;
}
BinaryTreeNode::~BinaryTreeNode()
{
    delete left;
    delete right;
}
int BinaryTreeNode::get_value()
{
    return value;
}
void BinaryTreeNode::set_value(int value)
{
    this->value = value;
}
BinaryTreeNode* BinaryTreeNode::get_left()
{
    return left;
}
void BinaryTreeNode::set_left(BinaryTreeNode* left)
{
    this->left = left;
}
BinaryTreeNode* BinaryTreeNode::get_right()
{
    return right;
}
void BinaryTreeNode::set_right(BinaryTreeNode* right)
{
    this->right = right;
}

class SpecialBinaryTree
{
private:
    BinaryTreeNode *root;
public:
    SpecialBinaryTree();
    ~SpecialBinaryTree();
    bool add_node (int new_value, int parent_value, bool is_left_child, bool is_right_child, bool is_root);
    bool update_value (int previous_value, int new_value);
    bool remove_node (int value);
    int is_leaf_node (int value);
    bool does_exist_in_subtree(int subtree_root_value, int value_to_search);
    int find_depth (int value);
    int find_height (int value);
    void preorder_traversal();
    void postorder_traversal();
    void inorder_traversal();
    int find_sum_of_values_in_subtree(int subtree_root_val);
    int find_minimum_value_in_subtree(int subtree_root_val);
    int find_maximum_value_in_subtree(int subtree_root_val);

    BinaryTreeNode* find_node(BinaryTreeNode* root, int value);
    int calculate_height(BinaryTreeNode* node);
    int calculate_depth(BinaryTreeNode* node, int value, int depth);
    
};

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
        // Node to be removed does not exist
        return false;
    }

    // Find the parent of the node to be removed
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

    // Replace the node's value with its left child's value until a leaf node is reached
    while (node->get_left() != nullptr || node->get_right() != nullptr) {
        if (node->get_left() != nullptr) {
            // Replace with left child's value
            node->set_value(node->get_left()->get_value());
            parent = node;
            node = node->get_left();
        } else {
            // Replace with right child's value
            node->set_value(node->get_right()->get_value());
            parent = node;
            node = node->get_right();
        }
    }

    // Remove the leaf node
    if (parent != nullptr) {
        if (parent->get_left() == node) {
            parent->set_left(nullptr);
        } else {
            parent->set_right(nullptr);
        }
    } else {
        // If the node to be removed is the root
        root = nullptr;
    }

    // Delete the node
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
        return -1; // Node doesn't exist, return -1
    }

    return calculate_depth(root, value, 0);
}

int SpecialBinaryTree::calculate_depth(BinaryTreeNode* node, int value, int depth) {
    if (node == nullptr) {
        return -1; // Node doesn't exist, return -1
    }

    if (node->get_value() == value) {
        return depth; // Found the node, return the depth
    }

    // Recursively search the left and right subtrees
    int left_depth = calculate_depth(node->get_left(), value, depth + 1);
    int right_depth = calculate_depth(node->get_right(), value, depth + 1);

    // Return the maximum depth from the left and right subtrees
    return max(left_depth, right_depth);
}


int SpecialBinaryTree::find_height(int value) {
    BinaryTreeNode* current = find_node(root, value); // Find the node first
    if (current == nullptr) {
        return -1; // Node doesn't exist, return -1
    }
    
    // Calculate the height of the subtree rooted at the given node
    int left_height = calculate_height(current->get_left());
    int right_height = calculate_height(current->get_right());
    
    // Return the maximum height of the left and right subtrees
    return std::max(left_height, right_height);
}

int SpecialBinaryTree::calculate_height(BinaryTreeNode* node) {
    if (node == nullptr) {
        return 0; // Height of an empty subtree is 0
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





int main() {

    string truth_table[2] = {"false", "true"};

    SpecialBinaryTree t;

    cout<<truth_table[t.add_node( 4, -1, false, false, true)]<<endl; // we are adding the root node
    cout<<truth_table[t.add_node( 8, 4, true, false, false)]<<endl; 
    cout<<truth_table[t.add_node( 2, 4, false, true, false)]<<endl;
    cout<<truth_table[t.add_node( 16, 8, true, false, false)]<<endl;
    cout<<truth_table[t.add_node( 1, 8, false, true, false)]<<endl;
    cout<<truth_table[t.add_node( 7, 1, true, false, false)]<<endl;
    cout<<truth_table[t.add_node( 3, 2, true, false, false)]<<endl;
    cout<<truth_table[t.add_node( 9, 3, true, false, false)]<<endl;
    cout<<truth_table[t.add_node( 5, 2, false, true, false)]<<endl;
    cout<<truth_table[t.add_node( 10, 3, false, true, false)]<<endl;
    cout<<truth_table[t.add_node( 6, 10, true, false, false)]<<endl;
    cout<<truth_table[t.add_node( 11, 6, false, true, false)]<<endl;
    cout<<truth_table[t.add_node( 13, 11, false, true, false)]<<endl;
    cout<<truth_table[t.add_node( 12, 11, true, false, false)]<<endl;
    cout<<endl;

    t.preorder_traversal();
    cout<<endl;
    t.postorder_traversal();
    cout<<endl;
    t.inorder_traversal();
    cout<<endl;

    cout<<truth_table[t.does_exist_in_subtree(4,13)]<<endl;
    cout<<truth_table[t.does_exist_in_subtree(4,14)]<<endl;
    cout<<truth_table[t.does_exist_in_subtree(10,12)]<<endl;
    cout<<truth_table[t.does_exist_in_subtree(10,5)]<<endl;
    cout<<truth_table[t.does_exist_in_subtree(7,7)]<<endl;
    cout<<truth_table[t.does_exist_in_subtree(7,8)]<<endl;
    cout<<truth_table[t.does_exist_in_subtree(20,40)]<<endl;
    cout<<endl;
    
    cout << t.find_depth(1) <<  endl;
    cout << t.find_height(1) << endl;
    cout << endl;
    
    cout << t.find_depth(2) <<  endl;
    cout << t.find_height(2) << endl;
    cout << endl;
    
    cout << t.find_depth(3) <<  endl;
    cout << t.find_height(3) << endl;
    cout << endl;
    
    cout << t.find_depth(4) <<  endl;
    cout << t.find_height(4) << endl;
    cout << endl;
    
    cout << t.find_depth(5) <<  endl;
    cout << t.find_height(5) << endl;
    cout << endl;
    
    cout << t.find_depth(6) <<  endl;
    cout << t.find_height(6) << endl;
    cout << endl;
    
    cout << t.find_depth(7) <<  endl;
    cout << t.find_height(7) << endl;
    cout << endl;
    
    cout << t.find_depth(8) <<  endl;
    cout << t.find_height(8) << endl;
    cout << endl;
    
    cout << t.find_depth(9) <<  endl;
    cout << t.find_height(9) << endl;
    cout << endl;
    
    cout << t.find_depth(10) <<  endl;
    cout << t.find_height(10) << endl;
    cout << endl;
    
    cout << t.find_depth(11) <<  endl;
    cout << t.find_height(11) << endl;
    cout << endl;
    
    cout << t.find_depth(12) <<  endl;
    cout << t.find_height(12) << endl;
    cout << endl;
    
    cout << t.find_depth(13) <<  endl;
    cout << t.find_height(13) << endl;
    cout << endl;
    
    cout << t.find_depth(14) <<  endl; /* It should return -1 since there is no node with value 14 */
    cout << t.find_height(14) << endl; /* It should return -1 since there is no node with value 14 */
    cout << endl;
    
    cout << t.find_depth(15) <<  endl; /* It should return -1 since there is no node with value 15 */
    cout << t.find_height(15) << endl; /* It should return -1 since there is no node with value 15 */
    cout << endl;
    
    cout << t.find_depth(16) <<  endl;
    cout << t.find_height(16) << endl;
    cout << endl;


    return 0;
}