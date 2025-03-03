#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node()
    {
        // cout << "I am inside default constructor" << endl;
        this->next = NULL;
    }
    Node(int data)
    {
        // cout << "I am inside parameterized constructor" << endl;
        this->data = data;
        this->next = NULL;
    }
};

void printLL(Node *head)
{
    Node *temp = head; // chances of error in code due to this line.
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << endl;
}

int getLength(Node *head)
{
    Node *temp = head;
    int count = 0;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

int main()
{

    // Creation of Node
    // Node a; // static allocation
    Node *first = new Node(10); // dynmaic allocation
    Node *second = new Node(20);
    Node *third = new Node(30);
    Node *fourth = new Node(40);
    Node *fifth = new Node(50);

    first->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    // linked list create ho chuki hai

    Node *head = first;
    cout << "Printing the entire LL: " << endl;
    printLL(head);

    cout << "Length of LL is : ";
    int length = getLength(head);
    cout << length;

    return 0;
}