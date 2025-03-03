#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *prev;
    Node *next;

    Node()
    {
        this->prev = NULL;
        this->next = NULL;
    }

    Node(int data)
    {
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }
};

void printDLL(Node *head)
{
    cout << "NULL->";
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int findLength(Node *head)
{
    int count = 0;
    Node *temp = head;
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
        // LL is empty
        Node *newNode = new Node(data);
        head = newNode;
        tail = newNode;
    }
    else
    {
        // LL is Non-empty
        // step 1:
        Node *newNode = new Node(data);
        // step 2:
        head->prev = newNode;
        // step 3:
        newNode->next = head;
        // step 4:
        head = newNode;
    }
}
void insertAtTail(Node *&head, Node *&tail, int data)
{
    // empty LL
    if (head == NULL)
    {
        Node *newNode = new Node(data);
        head = newNode;
        tail = newNode;
    }
    // Non-emptyLL
    else
    {
        Node *newNode = new Node(data);
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}
void insertAtAnyPosition(Node *&head, Node *&tail, int data, int position)
{
    int len = findLength(head);
    // empty LL
    if (head == NULL)
    {
        Node *newNode = new Node(data);
        head = newNode;
        tail = newNode;
    }
    // Non-empty LL
    else
    {
        // insertAtHead
        if (position == 1)
        {
            insertAtHead(head, tail, data);
        }
        // insertAtTail
        else if (position == len + 1)
        {
            insertAtTail(head, tail, data);
        }
        else
        {
            // insertAtAnyPosition
            Node *newNode = new Node(data);
            Node *prevNode = NULL;
            Node *currNode = head;
            int currPosition = 1;
            while (currPosition < position)
            {
                prevNode = currNode;
                currNode = currNode->next;
                currPosition++;
            }
            prevNode->next = newNode;
            newNode->prev = prevNode;
            newNode->next = currNode;
            currNode->prev = newNode;
        }
    }
}
void deleteNode(Node *&head, Node *&tail, int position)
{
    int len = findLength(head);
    // empty DLL
    if (head == NULL)
    {
        cout << "Can't delete coz DLL is empty" << endl;
        return;
    }
    else if (position < 1 || position > len)
    {
        cout << "Invalid position" << endl;
        return;
    }
    else if (head == tail)
    {
        // single element case
        Node *temp = head;
        delete temp;
        head = NULL;
        tail = NULL;
    }
    // Non-empty DLL
    else
    {
        // deletion from head
        if (position == 1)
        {
            Node *temp = head;
            head = head->next;
            temp->next = NULL;
            head->prev = NULL;
            delete temp;
        }
        // deletion from last
        else if (position == len)
        {
            Node *prevNode = tail->prev;
            prevNode->next = NULL;
            tail->prev = NULL;
            delete tail;
            tail = prevNode;
        }
        // delete from Middle
        else
        {
            Node *prevNode = NULL;
            Node *currNode = head;
            Node *nextNode = head->next;
            int currPosition = 1;
            while (currPosition < position)
            {
                prevNode = currNode;
                currNode = nextNode;
                nextNode = nextNode->next;
                currPosition++;
            }
            prevNode->next = nextNode;
            currNode->prev = NULL;
            currNode->next = NULL;
            nextNode->prev = prevNode;
            delete currNode;
        }
    }
}
int main()
{
    Node *head = NULL;
    Node *tail = NULL;

    insertAtHead(head, tail, 50);
    insertAtHead(head, tail, 40);
    insertAtHead(head, tail, 30);
    insertAtHead(head, tail, 20);
    insertAtHead(head, tail, 10);
    printDLL(head);
    cout << endl;
    // insertAtTail(head, tail, 50);
    // printDLL(head);
    // cout << endl;
    // insertAtAnyPosition(head, tail, 25, 3);
    // printDLL(head);

    deleteNode(head, tail, 3);
    printDLL(head);
    cout << endl;
    return 0;
}