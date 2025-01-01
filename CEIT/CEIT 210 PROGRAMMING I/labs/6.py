import random
word = random.choice(
  ["RECURSION", "ITERATION", 'CONDITIONS', 'PROGRAMMING', 'VARIABLES'])
unknown = len(
  word) * '_'  #TO PRINT THE  WORD TO BE GUESSES IN THIS FORMAT ________
points = 12
print("Word Prediction Game")
print(unknown)
print('\nThe word has', len(word), 'letters.')
print('You have', points, 'points in total to start with.')
print('You can buy a letter at a cost of 2 points.')
print('You can buy 4 letters at max.')
print('You can make a guess at max 3 times.')
print('Each wrong guess results in 2 point loss.\n')

wordBuyedCounter = 0
guessCounter = 3
won = False
while True:
    if won == False:
        if guessCounter > 0 and points > 0:
            print("\n*** Remaining points:",points,"***")
            print('''
1. Make a guess
2. Buy a letter
        ''')
            choice = input("What to do?: ")

            if choice == "1":
                while guessCounter > 0:

                    userGuess = input("\nMake your guess: ")
                    if userGuess.upper() == word:
                        won = True
                        break
                    else:
                        print("\nIncorrect guess!\n")
                        points -= 2
                        guessCounter -= 1
                        break

            elif choice == "2":
                if points > 2:
                    while "_" in unknown:
                        if wordBuyedCounter < 4:
                            indexOfWord = random.randint(0, len(word) - 1)
                            while unknown[indexOfWord] != "_":
                                indexOfWord = random.randint(0, len(word) -1)
                            unknown = unknown[:indexOfWord] + word[indexOfWord] + unknown[indexOfWord+1:]
                            print("\nThe word puchased is ",word[indexOfWord])
                            print("\n",unknown)

                            wordBuyedCounter += 1
                            points -= 2
                            break
                        else:
                            print("You cannot buy more letters.")
                            break
                else:
                    print("\nYou cannot buy a letter.")
                    print("Otherwise, the game will end.")
        else:
            print("The game ended")
            print("No points left or you have finished your guesses.")
            print(f"The answer was {word}")
            break
    else:
        print("Correct guess! You won!")
        break
