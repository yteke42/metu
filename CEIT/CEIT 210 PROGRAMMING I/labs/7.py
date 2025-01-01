import random

def userInfo():
    user = input("Press y to play rolling dice: ")
    return user

def loop():
    userCounter = 0
    pcCounter = 0
    drawCounter = 0

    with open("user.txt", "r") as file:
        for line in file.readlines():
            userRoundCounter = line
    with open("computer.txt", "r") as file:
        for line in file.readlines():
            pcRoundCounter = line
    user = userInfo()
    if user == "y" or user == "Y":
        while (userCounter + pcCounter < 5):
            try:
                while True:
                    randomUser = int(input("Enter a value between 1 and 6: "))
                    if randomUser not in range(1,7):
                        print("The value is out of range.")
                        continue
                    else:
                        break
            except ValueError or TypeError:
                print("You entered an invaild number.")
                pass
            else:
                randomPC = random.randrange(1, 7)
                if randomUser > randomPC:
                    userCounter += 1
                    print("User wins!", userCounter,"vs",pcCounter)
                elif randomPC > randomUser:
                    pcCounter += 1
                    print("Computer wins!", userCounter,"vs",pcCounter)
                else:
                    pcCounter += 1
                    userCounter += 1
                    drawCounter += 1
                    print("Draw, no winer!", userCounter,"vs",pcCounter)
        print("\nReporting the results:")
        if userCounter > pcCounter:
            print("THE WINNER OF THE ROUND IS USER")
            # If the user.txt has a number, increase it
            # If the user.txt has no number in it yet, write 1 inside
            with open("user.txt", "w") as file:
                file.truncate()
                try:
                    file.write(f"{int(userRoundCounter)+1}")
                except UnboundLocalError:
                    file.write("1")
                    howManyTimesUserWon = 1
                else:
                    file.close()
        elif pcCounter > userCounter:
            print("THE WINNER OF THE ROUND IS COMPUTER.")
            # If the computer.txt has a number, increase it
            # If the computer.txt has no number in it yet, write 1 inside
            with open("computer.txt", "w") as file:
                file.truncate()
                try:
                    file.write(f"{int(pcRoundCounter)+1}")
                except UnboundLocalError:
                    file.write("1")
                    howManyTimesPcWon = 1
                else:
                    file.close()
        else:
            print("IT IS A TIE!")
        print("Total number of dice rolls: ",userCounter + pcCounter )
        print("The user won", userCounter, "times.")
        print("The computer won", pcCounter, "times.")
        print("The draws were", userCounter, "times.")
        print()
        print("---ROUNDS WON SO FAR---")
        with open("user.txt", "r") as file:
            for line in file.readlines():
                howManyTimesUserWon = line
            file.close()
        with open("computer.txt", "r") as file:
            for line in file.readlines():
                howManyTimesPcWon = line
            file.close()
       
        try:
            print(f"User won {howManyTimesUserWon} rounds.")
        except UnboundLocalError:
            howManyTimesUserWon = 0
            print(f"User won {howManyTimesUserWon} rounds.")
       
        try:
            print(f"Computer won {howManyTimesPcWon} rounds.")
        except UnboundLocalError:
            howManyTimesPcWon = 0
            print(f"Computer won {howManyTimesPcWon} rounds.")

        loop()
    else:
        print("The game has ended.")
loop()
