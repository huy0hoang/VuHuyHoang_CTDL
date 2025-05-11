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

class Doctor(Person):
    def __init__(self, name: str, yob: int, specialist: str):
        super().__init__(name, yob)  # Kế thừa từ lớp Person
        self._specialist = specialist  # Thêm thuộc tính chuyên khoa

    def describe(self):
        print(f"Doctor Name: {self._name}, Year of Birth: {self._yob}, Specialist: {self._specialist}")

doctor1 = Doctor(name="doctorZ2023", yob=1981, specialist="Endocrinologists")
assert doctor1._yob == 1981
doctor1.describe()
