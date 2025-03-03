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

int main()
{
  // Node *root = NULL;
  // createBST(root);

  int inOrder[] = {10, 20, 30, 40, 50, 60, 70};
  int size = 7;
  int start = 0;
  int end = size - 1;

  Node* root = BSTFromInOrder(inOrder, start, end);

  levelOrderTraversal(root);

  return 0;
}