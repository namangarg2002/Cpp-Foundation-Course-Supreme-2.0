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
    cout << "NULL" << endl;
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
void insertAtHead(Node *&head, Node *&tail, int data)
{
    if (head == NULL)
    {
        // empty case;
        Node *newNode = new Node(data);
        head = newNode;
        tail = newNode;
    }
    else
    {
        // Non-empty Case:
        Node *newNode = new Node(data);
        newNode->next = head;
        head = newNode;
    }
}
void insertAtTail(Node *&head, Node *&tail, int data)
{
    if (head == NULL)
    {
        // empty case
        Node *newNode = new Node(data);
        head = newNode;
        tail = newNode;
    }
    else
    {
        // Non-empty Case
        Node *newNode = new Node(data);
        tail->next = newNode;
        tail = newNode;
    }
}

void insertAtAnyPosition(Node *&head, Node *&tail, int data, int position)
{
    if (position < 1)
    {
        cout << "Can't Possible to insert here, please enter a valid position" << endl;
        return;
    }
    int length = getLength(head);

    if (position > length + 1)
    {
        cout << "Can't Possible to insert here, please enter a valid position" << endl;
        return;
    }

    if (position == 1)
    {
        insertAtHead(head, tail, data);
    }

    else if (position == length + 1)
    {
        insertAtTail(head, tail, data);
    }

    else
    {
        // insert at middle of LL

        // Step 1: creeate a new node
        Node *newNode = new Node(data);
        // step 2: traverse current/ previous node
        Node *prev = NULL;
        Node *curr = head;
        int currentPos = 1;
        while (currentPos < position)
        {
            prev = curr;
            curr = curr->next;
            currentPos++;
        }
        // step 3: attach prev to newNode
        prev->next = newNode;
        // step 4: attach newNode to Curr
        newNode->next = curr;
    }
}

int main()
{
    Node *head = NULL;
    Node *tail = NULL;

    insertAtTail(head, tail, 10);
    insertAtTail(head, tail, 20);
    insertAtTail(head, tail, 30);
    insertAtTail(head, tail, 50);
    printLL(head);

    insertAtAnyPosition(head, tail, 1000, 3);
    printLL(head);
    return 0;
}