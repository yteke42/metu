def PrintGameIntro():
    print("*********WELCOME TO THE GUESSING GAME***********")
    print('''
    The goal of this game to find the computer generated random number in several guesses.
    You will determine the range and more range means more guesses.
    ''')

import random

#USER DETERMINING THE RANGE
def GetTheLimits(count):
    high_err = False;
    low_err = False;
    if (count == 0):
        low = int(input('Lower limit: '))
        high = int(input('Higher limit: '))
    else:
        if (high_err):
            high = int(input('Higher limit: '))
        if (low_err):
            low = int(input('Lower limit: '))
    if (high > 100):
        print("Error. Upper limit should be equal to or less than 100\n")
        high_err = True
        GetTheLimits(count)
    if (low < 0):
        print("Error. Lower limit should be equal to or bigger than 0.\n")
        low_err = True
        GetTheLimits(count)

    if (low >= high):
        print("Error. Upper limit should be higher than lower limit.\n")
        low_err = True
        high_err = True
        GetTheLimits(count)

    count += 1
    return low, high

PrintGameIntro()
lowLim, highLim = GetTheLimits(0)

#CHOOSING RANDOM TARGET
randomTarget = random.randrange(lowLim, highLim)

#HOW MANY GUESSES ACCORDING TO THE LIMIT
def numberOfGuesses():
    if (highLim-lowLim > 39):
        MAX_GUESSES = 8
    elif (highLim-lowLim > 19):
        MAX_GUESSES = 6
    elif (highLim-lowLim > 9):
        MAX_GUESSES = 4
    else:
        MAX_GUESSES = 2
    return MAX_GUESSES

#GUESS COUNTER
guessCounter = 0
while True:
    userGuess = int(input("Take a guess: "))
    MAX_GUESSES = numberOfGuesses()
    #Increment the counter
    guessCounter += 1
    if userGuess == randomTarget:
        print("You got it!!!")
        print("It only took you", guessCounter, "guess(es).")
        break
    elif userGuess < randomTarget:
        if (randomTarget - userGuess >= 10):
            print("Go up a lot.")
            print("You have", (MAX_GUESSES - guessCounter), "guesses left.")
        elif (randomTarget - userGuess < 10):
            print("Go up a bit.")
            print("You have", (MAX_GUESSES - guessCounter), "guesses left.")
    elif userGuess > randomTarget:
        if (userGuess - randomTarget  >= 10):
            print("Go down a lot.")
            print("You have", (MAX_GUESSES - guessCounter), "guesses left.")
        elif (userGuess - randomTarget < 10):
            print("Go down a bit.")
            print("You have", (MAX_GUESSES - guessCounter), "guesses left.")
    if guessCounter == MAX_GUESSES:
        print("Sorry, you did not get it in", MAX_GUESSES, "guesses.")
        print("The number was:", randomTarget)
        break
