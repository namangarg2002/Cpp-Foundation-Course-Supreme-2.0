#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node()
    {
        this->next = NULL;
    }
    Node(int data)
    {
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

void insertAtHead(Node *&head, Node *&tail, int data)
{
    if (head == NULL)
    {
        // empty LL

        // create new Node
        Node *newNode = new Node(data);
        // update head
        head = newNode;
        tail = newNode;
    }
    else
    {

        // Non-empty LL

        // create new node
        Node *newNode = new Node(data);
        // attach new node to head node
        newNode->next = head;
        // update head
        head = newNode;
    }
}

void insertAtTail(Node *&head, Node *&tail, int data)
{
    if (head == NULL)
    {
        // empty LL

        // Step 1: create new node
        Node *newNode = new Node(data);
        // Step 2: single node hai entire list m
        // that's why head and tail ko ispar point karwado
        head = newNode;
        tail = newNode;
    }
    else
    {
        // Non-empty LL

        // Step 1: create new Node
        Node *newNode = new Node(data);
        // Step2: attach new node to tail
        tail->next = newNode;
        // Step3: update tail
        tail = newNode;
    }
}

int main()
{
    // Node *first = new Node(10); // dynmaic allocation
    // Node *second = new Node(20);
    // Node *third = new Node(30);
    // Node *fourth = new Node(40);
    // Node *fifth = new Node(50);

    // first->next = second;
    // second->next = third;
    // third->next = fourth;
    // fourth->next = fifth;

    // Node *head = first;
    // Node *tail = fifth;
    // cout << "Printing the entire LL: " << endl;
    // printLL(head);

    // insertAtTail(head, tail, 500);

    // printLL(head);

    Node *head = NULL;
    Node *tail = NULL;

    insertAtHead(head, tail, 10);
    insertAtHead(head, tail, 20);
    insertAtHead(head, tail, 30);
    insertAtTail(head, tail, 50);

    printLL(head);

    return 0;
}