#include <iostream>
#define MAX 100
using namespace std;

class StackArray {
private:
    int arr[MAX];
    int top;

public:
    StackArray() { top = -1; }

    void push(int x) {
        if (top >= MAX - 1) {
            cout << "Stack Overflow\n";
            return;
        }
        arr[++top] = x;
        cout << x << " pushed into Array Stack\n";
    }

    void pop() {
        if (top < 0) {
            cout << "Stack Underflow\n";
            return;
        }
        cout << arr[top--] << " popped from Array Stack\n";
    }

    int peek() {
        if (top < 0) {
            cout << "Stack is Empty\n";
            return -1;
        }
        return arr[top];
    }

    bool isEmpty() {
        return (top < 0);
    }
};

int main() {
    StackArray s;
    int choice, value;

    do {
        cout << "\n--- Array Stack Menu ---\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Peek\n";
        cout << "4. Check Empty\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to push: ";
            cin >> value;
            s.push(value);
            break;
        case 2:
            s.pop();
            break;
        case 3:
            cout << "Top element: " << s.peek() << "\n";
            break;
        case 4:
            if (s.isEmpty())
                cout << "Stack is empty\n";
            else
                cout << "Stack is not empty\n";
            break;
        case 5:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice\n";
        }
    } while (choice != 5);

    return 0;
}



