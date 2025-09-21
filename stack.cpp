#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;

// Template Stack class with dynamic resizing
template <typename T>
class Stack {
private:
    T* arr;                // dynamic array
    int capacity;          // current allocated size
    int topIndex;          // index of top element

    void resize() {
        int newCapacity = capacity * 2; //double the size
        T* newArr = new T[newCapacity]; //alocate bigger array
        for (int i = 0; i < capacity; i++) {
            newArr[i] = arr[i];     //copy old elements
        }
        delete[] arr;               //free old array
        arr = newArr;               //point to new array
        capacity = newCapacity;     //update capacity
    }

public:
    Stack(int initialCapacity = 4) {
        capacity = initialCapacity;
        arr = new T[capacity];      //alocate memory
        topIndex = -1;              //empty stack
    }

    ~Stack() {
        delete[] arr;
    }

    void push(const T& value) {
        if (topIndex + 1 == capacity) resize();   //full? double capacity
        arr[++topIndex] = value;                  //increment top index and assign
    }

    void pop() {
        if (topIndex == -1)
            throw runtime_error("Stack Underflow");
        topIndex--;                               //just move the pointer back 
    }

    T top() const {
        if (topIndex == -1)
            throw runtime_error("Stack is empty");
        return arr[topIndex];                    //return last element
    }

    int size() const {
        return topIndex + 1;
    }

    bool empty() const {
        return topIndex == -1;
    }
};

// User-defined type
struct Person {
    string name;
    int age;
    Person(string n, int a) : name(n), age(a) {}
    Person() : name(""), age(0) {}
};

int main() {
    // Stack of integers
    Stack<int> s1;
    s1.push(10);
    s1.push(20);
    cout << "Top of s1: " << s1.top() << endl;
    s1.pop();
    cout << "Size of s1: " << s1.size() << endl;

    // Stack of strings
    Stack<string> s2;
    s2.push("Hello");
    s2.push("World");
    cout << "Top of s2: " << s2.top() << endl;
    s2.pop();
    cout << "Size of s2: " << s2.size() << endl;

    // Stack of user-defined type
    Stack<Person> people;
    people.push(Person("Alice", 25));
    people.push(Person("Bob", 30));
    cout << "Top of people: " << people.top().name << ", " << people.top().age << endl;
    people.pop();
    cout << "Size of people: " << people.size() << endl;

    return 0;
}
