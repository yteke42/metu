class Student:
    dept = 'CEIT'
    def _init_(self, name, grades=None) -> None:
        if grades is None:
            grades = []
        self.name = name
        self.grades = grades
    def _str_(self) -> str:
        return f'{students.index(self) + 1}. {self.name}'
    def print_grade_status(self) -> None:
        max_score, max_exam = max([(grade.score, grade.exam_name) for grade in self.grades], key=lambda x: x[0])
        avg_score = sum([grade.score for grade in self.grades]) / len(self.grades)

        print(f'\nGrade Stats for {self.name}:')
        print(f'\tMax grade was in {max_exam} with a score of {max_score}')
        print(f'\tAverage grade is {avg_score:.1f}')

class Grade:
    def _init_(self, score, exam_name) -> None:
        self.score = score
        self.exam_name = exam_name


students = []


while True:
    print('''
1) Create a student
2) Add an exam score for a student
3) View exam report for a student
    ''')

    choice = input('Make a choice: ')

    if choice == '1':
        student_name = input('\nEnter a student name: ')
        student = Student(student_name)
        students.append(student)
        print('\nStudent is added.')
    elif choice == '2':
        if students:
            print('\nStudents are listed below:')
            print(*students, sep='\n')
            student = students[int(input('\nSelect a student: ')) - 1]

            print('\nEnter the grade info below.')
            exam = input('\tExam name: ')
            student_score = int(input('\tScore: '))
            grade = Grade(student_score, exam)

            student.grades.append(grade)
            print(f'\n{exam} grade ({student_score}) is added for {student.name}.')
        else:
            print('\nNo student has been added yet.')
    elif choice == '3':
        if students:
            print('\nStudents are listed below:')
            print(*students, sep='\n')
            student = students[int(input('\nSelect a student: ')) - 1]
            student.print_grade_status()
        else:
            print('\nNo student has been added yet.')
    else:
        break