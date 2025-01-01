def PrintGameIntro():
    print("*********WELCOME TO THE Scissor-Paper-Rock game.***********")
    print('''
    Rock smashes scissors.
    Paper covers rock.
    Scissors cut paper.\n''')
import random

def getuserGuess():
    userGuess = str(input("Enter a choice (rock, paper, scissors): "))
    return userGuess

def computersChoice():
    possible_choices = ["rock", "paper", "scissors"]
    randomGeneratedChoice = random.choice(possible_choices)
    return randomGeneratedChoice

def computeTheAnswer():
    userGuess = getuserGuess()
    randomGeneratedChoice = computersChoice()
    if userGuess == randomGeneratedChoice:
        print("Both players selected the", userGuess, "It's a tie!")

    elif userGuess == "scissors":
        if randomGeneratedChoice == "rock":
            print("Rock smashes scissors. You lose!")
        else:
            print("Scissors cuts paper. You win!")
   
    elif userGuess == "rock":
        if randomGeneratedChoice == "paper":
            print("Paper covers rock. You lose!")
        else:
            print("Rock smashes scissors. You win!")
   
    elif userGuess == "paper":
        if randomGeneratedChoice == "rock":
            print("Paper covers rock. You win!")
        else:
            print("Scissors cuts paper. You lose!")

PrintGameIntro()
computeTheAnswer()