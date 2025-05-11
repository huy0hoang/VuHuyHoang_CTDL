class MyStack:
    def __init__(self, capacity):
        self.__capacity = capacity
        self.__stack = []

    def is_full(self):
        return len(self.__stack) == self.__capacity

    def push(self, value):
        if not self.is_full():
            self.__stack.append(value)
        else:
            print("Stack is full, cannot push more elements!")

    def top(self):
        if len(self.__stack) > 0:
            return self.__stack[-1]  # Lấy phần tử trên cùng của stack
        else:
            return None  # Trả về None nếu stack rỗng

# Khởi tạo stack với sức chứa 5
stack1 = MyStack(capacity=5)

# Thêm các phần tử vào stack
stack1.push(1)
assert stack1.is_full() == False  # Stack chưa đầy
stack1.push(2)

# In phần tử trên cùng của stack
print(stack1.top())  
