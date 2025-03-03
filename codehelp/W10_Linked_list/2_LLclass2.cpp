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

void deleteNode(Node *&head, Node *&tail, int position)
{
    int len = getLength(head);
    // empty list
    if (head == NULL)
    {
        cout << "Cannot delete, coz LL is empty " << endl;
        return;
    }

    // single element case:
    if (head == tail)
    {
        Node *temp = head;
        delete temp;
        head = NULL;
        tail = NULL;
    }

    // delete from head
    if (position == 1)
    {
        // first node ko delete kr do
        Node *temp = head;
        head = temp->next;
        temp->next = NULL;
        delete temp;
    }

    else if (position == len)
    {
        // last node delete hoga

        // find previous
        Node *prev = head;
        while (prev->next != tail)
        {
            prev = prev->next;
        }
        // previous node ka link null karo
        prev->next = NULL;
        // delete tail;
        delete tail;
        // update tail
        tail = prev;
    }

    else
    {
        // middle element delete hoga
        // Step 1: traverse prev/curr node
        Node *prev = NULL;
        Node *curr = head;
        int currPosition = 1;
        while (currPosition < position)
        {
            prev = curr;
            curr = curr->next;
            currPosition++;
        }
        // step 2: allign previous next to current next node
        prev->next = curr->next;
        // step 3: isolate cureent node with null
        curr->next = NULL;
        // step 4: delete current node
        delete curr;
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

    printLL(head);
    cout << endl;

    deleteNode(head, tail, 6);

    printLL(head);
    cout << endl;
    return 0;
}