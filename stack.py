from typing import Generic, TypeVar

T = TypeVar('T')

class Stack(Generic[T]):
    def __init__(self):
        self.arr = []

    def push(self, value: T) -> None:
        self.arr.append(value)

    def pop(self) -> T:
        if not self.arr:
            raise Exception("Stack Underflow")
        return self.arr.pop()

    def top(self) -> T:
        if not self.arr:
            raise Exception("Stack is empty")
        return self.arr[-1]

    def size(self) -> int:
        return len(self.arr)

if __name__ == "__main__":
    # Stack of integers
    s1 = Stack[int]()
    s1.push(10)
    s1.push(20)
    print("Top (int):", s1.top())
    s1.pop()
    print("Size (int):", s1.size())

    # Stack of strings
    s2 = Stack[str]()
    s2.push("Hello")
    s2.push("World")
    print("Top (string):", s2.top())

    # User-defined type
    class Person:
        def __init__(self, name: str, age: int):
            self.name = name
            self.age = age

        def __repr__(self):
            return f"Person(name={self.name}, age={self.age})"

    people = Stack[Person]()
    people.push(Person("Alice", 25))
    people.push(Person("Bob", 30))
    top_person = people.top()
    print(f"Top (Person): {top_person.name}, {top_person.age}")
