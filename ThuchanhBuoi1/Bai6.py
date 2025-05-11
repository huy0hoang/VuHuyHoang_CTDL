from abc import ABC, abstractmethod

class Person(ABC):
    def __init__(self, name: str, yob: int):
        self._name = name
        self._yob = yob

    def get_yob(self):
        return self._yob

    @abstractmethod
    def describe(self):
        pass

class Teacher(Person):
    def __init__(self, name: str, yob: int, subject: str):
        super().__init__(name, yob)  # Kế thừa constructor từ Person
        self._subject = subject  # Thêm thuộc tính subject

    def describe(self):
        print(f"Teacher Name: {self._name}, Year of Birth: {self._yob}, Subject: {self._subject}")

teacher1 = Teacher(name="teacherZ2023", yob=1991, subject="History")
assert teacher1._yob == 1991
teacher1.describe()
