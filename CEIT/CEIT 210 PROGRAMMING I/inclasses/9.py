print("Welcome to Spanish / English Dictionary")

myDict = {
    "car":"coche",
    "flower":"flor",
    "table":"mesa",
    "rug":"alfombra",
}

while True:
    print()
    print("\t 1) Add new entry")
    print("\t 2) Translate to Spanish")
    print("\t 3) Update an entry")
    print("\t 4) Quit")

    choice = input("What to do?: ")
    if choice == "1":
        addEngWord = str(input("Enter the English word: "))
        addSpnWord = str(input("Enter the Spanish word: "))
        addEngWord = addEngWord.lower()
        addSpnWord = addSpnWord.lower()
        while True:
            if addEngWord in myDict:
                print(f"\nThe word '{addEngWord}' is already in the dictionary.")
                break
            elif addSpnWord in myDict.values():
                print(f"\nThe word '{addSpnWord}' is already in the dictionary.")
                break
            else:
                myDict[addEngWord] = addSpnWord
                print("New word is added.")
                break
       
    elif choice == "2":
        userWord = input("Enter the English word: ")
        if userWord.lower() in myDict.keys():

            print(f"\t{userWord} means {myDict[userWord]} in Spanish.")
        else:
            print(f"The word '{userWord}' is not in the dictionary.")

    elif choice == "3":
        userWord = input("Enter the English word: ")
       
        if userWord.lower() in myDict.keys():
            print(f'{userWord} means {myDict[userWord]} in Spanish.')
            newSpanishWord = input('\nEnter the new Spanish word: ')
            myDict[userWord] = newSpanishWord
            print('\nThe dictionary is updated.\n')

        else:
            print(f"The word '{userWord}' is not in the dictionary.")

    elif choice == "4":
        print("Bye")
        break

