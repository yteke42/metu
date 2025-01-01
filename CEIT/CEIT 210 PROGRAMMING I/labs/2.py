todaysYear = 2022
todaysMonth = 10
todaysDay = 11
birthYear = int(input("Please enter your birth year:\n"))
birthMonth = int(input("Please enter your birth month:\n"))
birthDay = int(input("Please enter your birth day:\n"))
def dayCalculator(year, month, day):
    return((todaysDay - day) + (todaysMonth - month) *30 + (todaysYear - year) * 365 )

daysLived = dayCalculator(birthYear, birthMonth, birthDay)

print("This person has been living for", daysLived, "days.")

def hoursCalculator(year, month, day):
    return(dayCalculator(year, month, day) *24)
hoursLived = hoursCalculator(birthYear, birthMonth, birthDay)
print("This person has been living for",hoursLived, "hours.")