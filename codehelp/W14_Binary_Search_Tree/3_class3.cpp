#include <iostream>
#include <queue>
using namespace std;

class Node
{
public:
  int data;
  Node *left;
  Node *right;

  Node(int val)
  {
    this->data = val;
    this->left = NULL;
    this->right = NULL;
  }
};

// Node *insertIntoBST(Node *root, int data)
// {
//   if (root == NULL)
//   {
//     return new Node(data);
//   }

//   // it's not thr first node
//   if (data > root->data)
//   {
//     root->right = insertIntoBST(root->right, data);
//   }
//   else
//   {
//     root->left = insertIntoBST(root->left, data);
//   }
//   return root;
// }

// void createBST(Node *&root)
// {
//   cout << "Enter root data: ";
//   int data;
//   cin >> data;

//   while (data != -1)
//   {
//     root = insertIntoBST(root, data);
//     cout << "Enter data: ";
//     cin >> data;
//   }
// }

void levelOrderTraversal(Node *root)
{
  if (root == NULL)
  {
    cout << "Tree is empty!" << endl;
    return;
  }
  queue<Node *> q;
  q.push(root);
  q.push(NULL);
  while (!q.empty())
  {
    Node *front = q.front();
    q.pop();
    if (front == NULL)
    {
      cout << endl;
      if (!q.empty())
      {
        q.push(NULL);
      }
    }
    else
    {
      cout << front->data << " ";
      if (front->left != NULL)
      {
        q.push(front->left);
      }
      if (front->right != NULL)
      {
        q.push(front->right);
      }
    }
  }
}

Node *BSTFromInOrder(int inOrder[], int s, int e)
{
  // base case
  if (s > e)
  {
    return NULL;
  }
  // 1 case solve
  int mid = (s + e) / 2;
  int element = inOrder[mid];
  Node *root = new Node(element);

  // baki recursion handle kar lega
  root->left = BSTFromInOrder(inOrder, s, mid - 1);
  root->right = BSTFromInOrder(inOrder, mid + 1, e);

  return root;
}
// Convert this BST into sorte Order Doubly Linked List
void convertBSTtoDLL(Node *root, Node *&head)
{
  if (root == NULL)
  {
    return;
  }
  // RNL
  // R
  convertBSTtoDLL(root->right, head);
  // N
  // attaching next pointer of current node to head of LL
  root->right = head;
  // attaching prev pointer of head of LL to current node
  if (head != NULL)
  {
    head->left = root;
  }
  // head update
  head = root;
  // L
  convertBSTtoDLL(root->left, head);
}

Node *convertDLLtoBST(Node *&head, int n)
{
  // base case
  if (head == NULL || n <= 0)
  {
    return NULL;
  }

  // LNR

  // L
  Node *leftSubtree = convertDLLtoBST(head, n / 2);
  // N
  Node *root = head;
  root->left = leftSubtree;
  // head update
  head = head->right;
  // R
  Node *rightSubtree = convertDLLtoBST(head, n - (n / 2) - 1);
  root->right = rightSubtree;

  return root;
}

void printLinkedList(Node *head)
{
  Node *temp = head;
  cout << "Printing the entire list: " << endl;
  while (temp != NULL)
  {
    cout << temp->data << "->";
    temp = temp->right;
  }
  cout << endl;
}

int main()
{

  Node *first = new Node(10);
  Node *second = new Node(20);
  Node *third = new Node(30);

  first->left = NULL;
  first->right = second;
  second->left = first;
  second->right = third;
  third->left = second;
  third->right = NULL;

  Node *head = first;
  // 10<->20<->30

  Node *root = convertDLLtoBST(head, 3);
  levelOrderTraversal(root);

  // // Node *root = NULL;
  // // createBST(root);

  // int inOrder[] = {10, 20, 30, 40, 50, 60, 70};
  // int size = 7;
  // int start = 0;
  // int end = size - 1;

  // Node *root = BSTFromInOrder(inOrder, start, end);

  // levelOrderTraversal(root);
  // Node *head = NULL;
  // convertBSTtoDLL(root, head);
  // printLinkedList(head);

  return 0;
}