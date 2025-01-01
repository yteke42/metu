print("Welcome to Spanish / English Dictionary")

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
       
        with open("data.txt", "a") as file:
            file.write(f"\n{addEngWord},{addSpnWord}")
        print("New word is added.")

    elif choice == "2":
        userWord = input("Enter the English word: ")

        with open("data.txt", "r") as file:
            for line in file.readlines():
                engWord, spnWord = line.split(",")
                if userWord == engWord:
                    print(f"{engWord} means {spnWord} in Spanish.")

    elif choice == "3":
        userWord = input("Enter the English word: ")
        with open("data.txt", "r") as fp:
            lines = fp.readlines()

        for line in lines:
            engWord, spnWord = line.split(',')
            if userWord == engWord:
                print(f'{userWord} means {spnWord} in Spanish.')
                newSpanishWord = input('\nEnter the new Spanish word: ')

                lines[lines.index(line)] = f'{engWord},{newSpanishWord}'
                with open('data.txt', 'w') as updated_file:
                    updated_file.writelines(lines)

                print('\nThe dictionary is updated.\n')


    elif choice == "4":
        print("Bye")
        break
