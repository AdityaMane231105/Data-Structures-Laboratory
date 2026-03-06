#include <iostream>
#include <cstdlib>
using namespace std;

struct node
{
    int data;
    node *next;
};

node *front = NULL;
node *rear = NULL;

void push()
{
    int value;
    node *temp;

    temp = new node;

    cout << "Enter value: ";
    cin >> value;

    temp->data = value;
    temp->next = NULL;

    if(front == NULL)
    {
        front = rear = temp;
    }
    else
    {
        rear->next = temp;
        rear = temp;
    }

    cout << "Inserted: " << value << endl;
}

void pop()
{
    node *temp;

    if(front == NULL)
    {
        cout << "Queue Underflow" << endl;
    }
    else
    {
        temp = front;
        cout << "Deleted: " << front->data << endl;
        front = front->next;
        delete temp;
    }
}

void display()
{
    node *temp;

    if(front == NULL)
    {
        cout << "Queue is Empty" << endl;
    }
    else
    {
        temp = front;
        cout << "Queue elements are:" << endl;

        while(temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
}

int main()
{
    int choice;

    while(1)
    {
        cout << "\n1. Push\n2. Pop\n3. Display\n4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch(choice)
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



