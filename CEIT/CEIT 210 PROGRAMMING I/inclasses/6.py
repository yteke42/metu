import random
word = random.choice(["RECURSION", "ITERATION", 'CONDITIONS', 'PROGRAMMING', 'VARIABLES'])
unknown = len(word) * '_'  #TO PRINT THE  WORD TO BE GUESSES IN THIS FORMAT ________
print(unknown)


while "_" in unknown:
    getInput = input("Press Enter to reveal a letter [q to quit]: ")
    if getInput == "q" or getInput == "Q":
        print("The game has ended.")
    else:
        indexOfWord = random.randint(0, len(word) - 1)
        while unknown[indexOfWord] != "_":
            indexOfWord = random.randint(0, len(word) -1)
        unknown = unknown[:indexOfWord] + word[indexOfWord] + unknown[indexOfWord+1:]
        print(unknown)
