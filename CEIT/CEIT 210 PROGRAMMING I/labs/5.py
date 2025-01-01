import random
studentsList = ["Fatma", "Taha", "Aras"]
questionList= ["What is the difference between while and for loops?", "How can you print custom error messages for runtime errors?"]

print("--STUDENT QUESTION GENERATOR--")
print()
print("Using this application you can manage students and questions.")
print(" .   You can also select a random question for a random student.")
print(" .")
print()
print("Existing students:")
for n in range(len(studentsList)):
    print(n+1,".",studentsList[n])
print()
print("Existing questions:")
for n in range(len(questionList)):
    print(n+1,".",questionList[n])

print('''
A -> Add student
M -> Move the student up in the list
R -> Remove student by name
RL -> Remove the last student
''')
print("------------------------------------------")
print('''
Choose one of the actions:
a -> Add question
r -> Remove question by item number
rl -> Remove last question
G -> Randomly assign a question to a student
Q -> Quit the application
''')

while True:
   
    choice = str(input("Please choose an action: "))
    if choice == "A":
        addToStudent = str(input("\nEnter the student name to be added: "))
        studentsList.append(addToStudent)
        print("New student is added.\n")

        for n in range(len(studentsList)):
            print(n+1,".",studentsList[n])
        print()
        print()

    elif choice == "M":
        for n in range(len(studentsList)):
            print(n+1,".",studentsList[n])

        ix = int(input("Enter the item number to move up: "))
        if ix != 1:
            studentsList.insert(ix-2,studentsList[ix-1])
            studentsList.pop(ix)
            print()
            for n in range(len(studentsList)):
                print(n+1,".",studentsList[n])
        else:
            print(f"Cannot be moved up. {studentsList[0]} is already at the top.")


    elif choice == "R":
        studentToTemove = str(input("\nEnter the student name to be removed: "))
        if studentToTemove in studentsList:
            studentsList.remove(studentToTemove)
            print("The student is deleted.\n")
            for n in range(len(studentsList)):
                print(n+1,".",studentsList[n])
            print()
            print()
        else:
            print("This student is not in the list.")
   
    elif choice == "RL":
        studentsList.pop()
        print("\nThe last student in the list is deleted.\n")
        for n in range(len(studentsList)):
                print(n+1,".",studentsList[n])
        print()
        print()

    elif choice == "a":
        newQuestion = str(input("Enter a question to be added: "))
        questionList.append(newQuestion)
        print("New question is added.\n")

        for n in range(len(questionList)):
            print(n+1,".",questionList[n])
        print()
        print()

    elif choice == "r":
        for n in range(len(questionList)):
            print(n+1,".",questionList[n])        
        questionNumberToRemove = int(input("\nEnter the question number to be removed: "))
        if questionNumberToRemove <= len(questionList):
            questionList.pop(questionNumberToRemove-1)
            print("The question is deleted.\n")
            for n in range(len(questionList)):
                print(n+1,".",questionList[n])
            print()
            print()
        else:
            print("There is no such question.")

    elif choice == "rl":
        questionList.pop()
        print("\nThe last question in the list is deleted.\n")
        for n in range(len(questionList)):
                print(n+1,".",questionList[n])
        print()
        print()

    elif choice == "G":
        print(random.choice(questionList),"is asked for",random.choice(studentsList))
        print()

    elif choice == "Q":
        print("Goodbye.")
        break
   
    else:
        print("No such command.")