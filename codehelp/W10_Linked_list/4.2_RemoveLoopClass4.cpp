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

Node *getStartingPointOfLoop(Node *&head)
{
    // check for loop
    Node *slow = head;
    Node *fast = head;
    while (fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            fast = fast->next;
            slow = slow->next;
        }
        if (fast == slow)
        {
            break;
        }
    }
    if (fast == NULL)
    {
        return NULL;
    }
    // yaha pahuncha iska matlb loop present hai LL mai i.e., slow or fast meet kar gaye hai
    slow = head;

    // slow and fast 1-1 step move karenge
    while (fast != slow)
    {
        slow = slow->next;
        fast = fast->next;
    }
    // return starting point
    return slow;
}

void removeLoop(Node *&head)
{
    // check for loop
    Node *slow = head;
    Node *fast = head;
    while (fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            fast = fast->next;
            slow = slow->next;
        }
        if (fast == slow)
        {
            break;
        }
    }

    // yaha pahuncha iska matlb loop present hai LL mai i.e., slow or fast meet kar gaye hai
    slow = head;

    // slow and fast 1-1 step move karenge
    while (fast != slow)
    {
        slow = slow->next;
        fast = fast->next;
    }
    // Starting point
    Node *startPoint = slow;

    Node *temp = fast;
    while (temp->next != startPoint)
    {
        temp = temp->next;
    }
    temp->next = NULL;
}

int main()
{
    Node *head = NULL;
    Node *tail = NULL;

    insertAtHead(head, tail, 20);
    insertAtHead(head, tail, 50);
    insertAtHead(head, tail, 60);
    insertAtHead(head, tail, 90);
    insertAtTail(head, tail, 77);

    tail->next = head->next;

    cout << getStartingPointOfLoop(head)->data << endl;
    removeLoop(head);
    printLL(head);
    cout << endl;

    return 0;
}