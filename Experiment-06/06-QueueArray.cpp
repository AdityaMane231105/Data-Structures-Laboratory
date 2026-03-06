#include <iostream>
using namespace std;

#define MAX 5

int queue[MAX];
int front = -1;
int rear = -1;

void push()
{
    int value;

    if (rear == MAX - 1)
    {
        cout << "Queue Overflow" << endl;
    }
    else
    {
        cout << "Enter value: ";
        cin >> value;

        if (front == -1)
            front = 0;

        rear++;
        queue[rear] = value;

        cout << "Inserted: " << value << endl;
    }
}

void pop()
{
    if (front == -1 || front > rear)
    {
        cout << "Queue Underflow" << endl;
    }
    else
    {
        cout << "Deleted: " << queue[front] << endl;
        front++;
    }
}

void display()
{
    if (front == -1 || front > rear)
    {
        cout << "Queue is Empty" << endl;
    }
    else
    {
        cout << "Queue elements are: ";
        for (int i = front; i <= rear; i++)
        {
            cout << queue[i] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int choice;

    while (1)
    {
        cout << "\n1. Push\n2. Pop\n3. Display\n4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1: push(); break;
            case 2: pop(); break;
            case 3: display(); break;
            case 4: return 0;
            default: cout << "Invalid choice" << endl;
        }
    }

    return 0;
}


