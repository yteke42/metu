import random

def userInfo():
    user = input("Press y to play rolling dice: ")
    return user

def loop():
    userCounter = 0
    pcCounter = 0
    drawCounter = 0
    user = userInfo()
    if user == "y":
        while (userCounter + pcCounter < 5):
            randomUser = random.randrange(1, 7)
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
    else:
        print("The game has ended.")

    print("\nReporting the results:")
    print("Total number of dice rolls: ",userCounter + pcCounter )
    print("The user won", userCounter, "times.")
    print("The computer won", pcCounter, "times.")
    print("The draws were", userCounter, "times.")
    loop()
   
loop()
