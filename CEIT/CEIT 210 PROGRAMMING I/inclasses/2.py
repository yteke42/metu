def PrintTriangleIntro():
    print("*****************************************************")
    print("Computing Triangle Area")
    print("Enter height and base for the triangle. The area will be printed immediately.")

def PrintRectInfo():
    print("Computing Rectangle Area")
    print("Enter width and length for the rectangle. The area will be printed immediately.")

def PrintOutro():
    print("*****************************************************")
    print("The program ends.")


def conputeTriangleArea():
    triangleHeight, triangleBase = getInputforRectangle()
    print("The area of triangle is:", triangleBase * triangleHeight / 2)


def conputeRectangleArea():
    rectangleHeight, rectangleBase = getInputforRectangle()
    print("The area of triangle is:", rectangleHeight * rectangleBase)


def getInputforTriangle():
    triangleHeight = int(input("Enter the height:"))
    triangleBase = int(input("Enter the base:"))
    return triangleBase, triangleHeight


def getInputforRectangle():
    rectangleHeight = int(input("Enter the height:"))
    rectangleWidth = int(input("Enter the width:"))
    return rectangleHeight, rectangleWidth

PrintTriangleIntro()
conputeTriangleArea()
PrintRectInfo()
conputeRectangleArea()
PrintOutro()