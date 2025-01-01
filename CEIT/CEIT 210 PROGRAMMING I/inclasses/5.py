englishList = ["car"]
spanishList = ["coche"]



while True:
    print('''
        1) Add item to the dictionary
        2) Search for a word (English to Spanish)
        3) Search for a word (Spanish to English)
        4) Print the dictionary
        5) Delete an item
        6) Quit
    ''')

    choice = input('\nWhat would you like to do? ')
    if choice == "1":
        addToEng = input("Enter the English word: ")
        englishList.append(addToEng)
        addToSpan = input("Enter the Spanish word: ")
        spanishList.append(addToSpan)

    elif choice == "2":
        searchForEng = input("Search for English: ")
        if searchForEng in englishList:
            ix = englishList.index(searchForEng)
            print("Spanish Word: ",spanishList[ix])
        else:
            print("This word is not in the list.")

    elif choice == "3":
        searchForSpa = input("Search for Spanish: ")
        if searchForSpa in spanishList:
            ix = spanishList.index(searchForSpa)
            print("English Word: ",englishList[ix])
        else:
            print("This word is not in the list.")

    elif choice == "4":
        for n in range(len(englishList)):
            print(englishList[n],":",spanishList[n])
       
    elif choice == "5":
       
        deleteItem1 = input("1) The word I want to delete is English. \n2)The word I want to delete is Spanish.\n  ")
        if deleteItem1 == "1":
            deleteWord = input("What is the English word you want to delete? :")
            nIndex = englishList.index(deleteWord)
            englishList.pop(nIndex)
            spanishList.pop(nIndex)
        elif deleteItem1 == "2":
            deleteWord1 = input("What is the Spanish word you want to delete? :")
            nnIndex = spanishList.index(deleteWord1)
            englishList.pop(nnIndex)
            spanishList.pop(nnIndex)
        else:
            print("Try again.")

    elif choice == "6":
        print("Goodbye")
        break