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


stack1 = MyStack(capacity=5)

stack1.push(1)
assert stack1.is_full() == False  
stack1.push(2)


print(stack1.is_full())  
