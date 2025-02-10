import unittest

class Student: 
    marks_range = (0, 10)
    
    def __init__(self, name, marks = []):
        self.name = name
        self.__marks = marks
    
    @property
    def average_mark(self):
        if len(self.__marks) == 0:
            raise ValueError
            
        return sum([mark for mark in self.__marks]) / len(self.__marks)
        
    @property
    def marks(self):
        return self.__marks
    
    @marks.setter
    def marks(self, new_marks):
        if not all(isinstance(mark, int) for mark in new_marks):
            raise TypeError
        if not all(self.marks_range[0] <= mark <= self.marks_range[1] for mark in new_marks):
            raise ValueError
            
        self.__marks = list(new_marks)
    
    def add_mark(self, new_mark):
        if not isinstance(new_mark, int):
            raise TypeError
        
        if not (self.marks_range[0] <= new_mark <= self.marks_range[1]):
            raise ValueError
        
        self.__marks.append(new_mark)
    
    def __str__(self):
        return f"Student: {self.name}, average mark: {self.average_mark}"


class Group: 
    def __init__(self, name, students = []):
        self.name = name    
        self.__students = students
        
    @property
    def students(self):
        return self.__students
        
    def add_student(self, new_student):
        if not isinstance(new_student, Student):
            raise TypeError
            
        self.__students.append(new_student)
        
    def remove_student(self, student):
        if not isinstance(student, Student):
            raise TypeError
        
        if student not in self.__students:
            raise ValueError
            
        self.__students.remove(student)
        
    @property
    def average_mark(self):
        if not self.__students:
            return 0.0 
            
        total_marks = []
        
        for student in self.__students:
            total_marks.extend(student.marks)

        if not total_marks:
            return 0.0
        return round(sum(total_marks) / len(total_marks), 1)
        
        




class TestStudent(unittest.TestCase):
    def setUp(self):
        class StudentWithRange(Student):
            marks_range = (0, 100)

        self.Student = StudentWithRange
        self.student = self.Student(name="John", marks=[85, 90, 95])

    def test_student_initialization(self):
        self.assertEqual(self.student.name, "John")
        self.assertEqual(self.student.marks, [85, 90, 95])

    def test_marks_setter_valid(self):
        self.student.marks = [70, 80, 90]
        self.assertEqual(self.student.marks, [70, 80, 90])

    def test_marks_setter_invalid_type(self):
        with self.assertRaises(TypeError):
            self.student.marks = [70, "eighty", 90]

    def test_marks_setter_invalid_value(self):
        with self.assertRaises(ValueError):
            self.student.marks = [70, 150, 90]

    def test_average_mark(self):
        self.assertAlmostEqual(self.student.average_mark, 90.0)

    def test_average_mark_zero_division(self):
        self.student.marks = []
        with self.assertRaises(ZeroDivisionError):
            _ = self.student.average_mark

    def test_add_mark_valid(self):
        self.student.add_mark(88)
        self.assertIn(88, self.student.marks)

    def test_add_mark_invalid_type(self):
        with self.assertRaises(TypeError):
            self.student.add_mark("eighty-eight")

    def test_add_mark_invalid_value(self):
        with self.assertRaises(ValueError):
            self.student.add_mark(110)

    def test_student_str(self):
        self.assertEqual(str(self.student), "Student: John, average mark: 90.0")


class TestGroup(unittest.TestCase):
    def setUp(self):
        class StudentWithRange(Student):
            marks_range = (0, 100)

        self.Student = StudentWithRange
        self.group = Group(name="Math Club")
        self.student1 = self.Student(name="Alice", marks=[85, 90])
        self.student2 = self.Student(name="Bob", marks=[70, 80])

    def test_group_initialization(self):
        self.assertEqual(self.group.name, "Math Club")
        self.assertEqual(self.group.students, [])

    def test_add_student(self):
        self.group.add_student(self.student1)
        self.assertIn(self.student1.name, self.group.students)


    def test_add_student_invalid_type(self):
        with self.assertRaises(TypeError):
            self.group.add_student("Not a Student")

    def test_delete_student(self):
        self.group.add_student(self.student1)
        self.group.delete_student(self.student1)
        self.assertNotIn(self.student1, self.group.students)

    def test_delete_student_invalid_type(self):
        with self.assertRaises(TypeError):
            self.group.delete_student("Not a Student")

    def test_average_mark(self):
        self.group.add_student(self.student1)
        self.group.add_student(self.student2)
        self.assertAlmostEqual(self.group.average_mark, 81.25)

    def test_average_mark_no_students(self):
        with self.assertRaises(ValueError):
            _ = self.group.average_mark


if __name__ == "__main__":
    unittest.main()
