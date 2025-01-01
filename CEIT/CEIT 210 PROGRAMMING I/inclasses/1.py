#The goal of activity is to calculate the total money in your wallet.

#define a variable to store the number of 1 dollar banknote
#your code goes here
oneDollarBanknote = 8
#define a variable to store the number of 5 dollar banknote
#your code goes here
fiveDollarBanknote = 6
#define a variable to store the number of 10 dollar banknote
#your code goes here
tenDollarBanknote = 7
#define a variable to store the number of 20 dollar banknote
#your code goes here
twentyDollarBanknote = 12
#define a variable to store the number of 50 dollar banknote
#your code goes here
fiftyDollarBanknote = 89
#calculate the total amount and store in a variable.
#your code goes here
totalAmountofDollars = (oneDollarBanknote) + (fiveDollarBanknote * 5) + (tenDollarBanknote * 10) + (twentyDollarBanknote * 20) + (fiftyDollarBanknote * 50)
#convert to turkish lira and store in a variable.(1$=18.60)
#your code goes here
totalTurkish = totalAmountofDollars * 18.60
#display the result in liras and in dollars
#your code goes here
print(totalAmountofDollars)
print(totalTurkish)



'''
The following program is written for calculating the perimeter and area of two triangles
Please fix the errors in the code. The program should output the area and perimeter of both triangles.
'''

#Triangle #1
height = 20
firstSide = 10
secondSide = 5
base= 12

area = (height * base)/2
perim = base + firstSide + secondSide


#Triangle #2
myHeight = 20
firstSid = 10
mySecondSide = 5
myBase = 10

secondArea = (myHeight * myBase)/2
secondPerim = myBase + mySecondSide + firstSid



print("First triangle area:", area, "First triangle perim:", perim )
print("Second triangle area:", secondArea, "Second triangle perim:", secondPerim )