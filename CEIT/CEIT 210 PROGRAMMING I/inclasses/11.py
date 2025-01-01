import math

class Shape:
    def __init__(self, id=0, name="Shape", borderColor="Black"):
        self.id=id
        self.name=name
        self.borderColor = borderColor

    def CalculatePerimeter(self):
        return "not computable"

    def CalculateArea(self):
        return "not computable"

    def __str__(self):
        return f"[{self.id}] {self.name}"

class Rectangle(Shape):
    def __init__(self, id, name, borderColor,
                 width, length):
        self.width=width
        self.length=length

        super().__init__(id, name, borderColor)

    def CalculatePerimeter(self):
        return 2 * (self.length + self.width)

    def CalculateArea(self):
        return self.length * self.width

    def __str__(self):
        p = self.CalculatePerimeter()
        a = self.CalculateArea()

        return "Rectangle: " + super().__str__() + f" | Area is {a}, Perim is {p}"

class Circle(Shape):
    def __init__(self, id, name, borderColor,
                 diameter, angle=360):
        self.diameter = diameter
        self.angle = angle
        self.radius = self.diameter / 2

        super().__init__(id, name, borderColor)

    def CalculateArea(self):
        return round(math.pi * self.radius**2 * self.angle/360, 2)

    def CalculatePerimeter(self):
        return round(math.pi * self.diameter, 2)

    def __str__(self):
        p = self.CalculatePerimeter()
        a = self.CalculateArea()

        return "Circle: " + super().__str__() + f" | Area is {a}, Perim is {p}"

class Triangle(Shape):
    def __init__(self, id, name, borderColor, leftSide, rightSide, bottomSide, height) -> None:
        super().__init__(id, name, borderColor)
        self.leftSide = leftSide
        self.rightSide = rightSide
        self.bottomSide = bottomSide
        self.height = height


    def CalculatePerimeter(self):
        return self.leftSide + self.rightSide + self.bottomSide

    def CalculateArea(self):
        return (self.bottomSide * self.height) /2

    def __str__(self) -> str:
        p = self.CalculatePerimeter()
        a = self.CalculateArea()
        return "Triangle: " + super().__str__() + f" | Area:{a}, Perimeter is {p}"
'''
c1 = Circle(1, "Big Circle", "Red", 10)
r1 = Rectangle(2, "Big rectangle", "Blue", 5, 10)
s1 = Shape(3, "Basic shape", "Black")


shapeList = [c1, r1, s1]
print(shapeList)

for item in shapeList:
    print(item)

print(isinstance(r1, Circle))
'''
shapeList = []

while True:

    print()
    print("\t 1) Add a shape")
    print("\t 2) Display a single shape")
    print("\t 3) List all shapes")

    choice = input("What do you do?: ")
    if choice == "1":
        print()
        print("\t 1) Circle")
        print("\t 2) Rectangle")
        print("\t 3) Triangle")
        choice2 = input("What type of shape do you want to add? ")
        if choice2 == "1":
            id = int(input("Enter the id for the shape: "))
            name = input("Enter the name for the shape: ")
            borderColor = input("Enter a border color for the shape: ")
            diameter = int(input("Enter the diameter: "))
            id = Circle(id, name, borderColor, diameter)
            shapeList.append(id)
            print("Circle is added.")

        elif choice2 == "2":
            id = int(input("Enter the id for the shape: "))
            name = input("Enter the name for the shape: ")
            borderColor = input("Enter a border color for the shape: ")
            width = int(input("Enter the width: "))
            length = int(input("Enter the length: "))
            id = Rectangle(id, name, borderColor, width, length)
            shapeList.append(id)
            print("Rectangle is added.")

        elif choice2 == "3":
            id = int(input("Enter the id for the shape: "))
            name = input("Enter the name for the shape: ")
            borderColor = input("Enter a border color for the shape: ")
            leftSide = int(input("Enter the left side of the triangle: "))
            rightSide = int(input("Enter the right side of the triangle: "))
            bottomSide = int(input("Enter the bottom side of the triangle: "))
            height = int(input("Enter the height of the triangle: "))
            id = Triangle(id, name, borderColor,leftSide, rightSide, bottomSide, height)
            shapeList.append(id)
            print("Triangle is added.")


    elif choice == '2':
        for shape in shapeList:
            print(f'[{shape.id}] {shape.name}')

        shape_id = int(input('Which shape do you want to know properties of (Choose an id): '))
        for shape in shapeList:
            if shape_id == shape.id:
                print(shape)
                break

    elif choice == "3":
        for item in shapeList:
            print(f"[{item.id}] [{item.name}]")

    else:
        break
