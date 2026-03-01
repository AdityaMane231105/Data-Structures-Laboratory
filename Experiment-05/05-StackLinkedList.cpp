#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class StackLinkedList {
private:
    Node* top;

public:
    StackLinkedList() { top = nullptr; }

    ~StackLinkedList() {
        while (top != nullptr) {
            Node* temp = top;
            top = top->next;
            delete temp;
        }
    }

    void push(int x) {
        Node* temp = new Node();
        temp->data = x;
        temp->next = top;
        top = temp;
        cout << x << " pushed into LinkedList Stack\n";
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack Underflow\n";
            return;
        }
        cout << top->data << " popped from LinkedList Stack\n";
        Node* temp = top;
        top = top->next;
        delete temp;
    }

    int peek() {
        if (isEmpty()) {
            cout << "Stack is Empty\n";
            return -1;
        }
        return top->data;
    }

    bool isEmpty() { return (top == nullptr); }
};

int main() {
    StackLinkedList s;
    int choice, value;
    do {
        cout << "\n--- Linked List Stack Menu ---\n";
        cout << "1. Push\n2. Pop\n3. Peek\n4. Check Empty\n5. Exit\n";
        cout << "Enter choice: ";
        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }
        switch (choice) {
            case 1:
                cout << "Value: ";
                cin >> value;
                s.push(value);
                break;
            case 2:
                s.pop();
                break;
            case 3:
                value = s.peek();
                if (value != -1) cout << "Top: " << value << "\n";
                break;
            case 4:
                cout << (s.isEmpty() ? "Empty\n" : "Not Empty\n");
                break;
            case 5:
                break;
        }
    } while (choice != 5);
    return 0;
}



