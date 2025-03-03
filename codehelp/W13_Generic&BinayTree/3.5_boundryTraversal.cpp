#include <iostream>
#include <queue>
#include <map>
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

Node *createTree()
{
  cout << "Enter the value for Node : ";
  int value;
  cin >> value;
  if (value == -1)
  {
    return NULL;
  }
  // create Node
  Node *root = new Node(value);
  cout << "Entering in left of: " << value << endl;
  root->left = createTree();
  cout << "Entering in right of: " << value << endl;
  root->right = createTree();
  return root;
}

void preOrder(Node *root)
{
  if (root == NULL)
  {
    return;
  }
  cout << root->data << " ";
  preOrder(root->left);
  preOrder(root->right);
}

void inOrder(Node *root)
{
  if (root == NULL)
  {
    return;
  }
  inOrder(root->left);
  cout << root->data << " ";
  inOrder(root->right);
}

void postOrder(Node *root)
{
  if (root == NULL)
  {
    return;
  }
  postOrder(root->left);
  postOrder(root->right);
  cout << root->data << " ";
}

void levelorderTraversal(Node *root)
{
  queue<Node *> q;
  q.push(root);
  q.push(NULL);

  while (!q.empty())
  {
    Node *temp = q.front();
    q.pop();

    if (temp == NULL)
    {
      cout << endl;
      if (!q.empty())
      {
        q.push(NULL);
      }
    }
    else
    {
      cout << temp->data << " ";
      if (temp->left != NULL)
      {
        q.push(temp->left);
      }
      if (temp->right != NULL)
      {
        q.push(temp->right);
      }
    }
  }
}

void printLeftBoundry(Node *root)
{
  // base case
  if (root == NULL)
    return;
  // go back when leaf node found
  if (root->left == NULL && root->right == NULL)
  {
    return;
  }
  cout << root->data << " ";
  // if it is possible to move left then go ahead but dont move in both direction i.e., left or right
  // possible to move left
  if (root->left != NULL)
  {
    printLeftBoundry(root->left);
  }
  else
  {
    // not possible to move left
    printLeftBoundry(root->right);
  }
}

void printLeafBoundry(Node *root)
{
  if (root == NULL)
    return;

  if (root->left == NULL && root->right == NULL)
  {
    cout << root->data << " ";
  }
  printLeafBoundry(root->left);
  printLeafBoundry(root->right);
}

void printRightBoundry(Node *root)
{
  if (root == NULL)
    return;

  if (root->left == NULL && root->right == NULL)
  {
    return;
  }
  if (root->right != NULL)
  {
    printRightBoundry(root->right);
  }
  else
  {
    printRightBoundry(root->left);
  }
  cout << root->data << " ";
}

void boundryTraversal(Node *root)
{
  if (root == NULL)
    return;
  cout << root->data << " ";
  printLeftBoundry(root->left);
  printLeafBoundry(root->left);
  printLeafBoundry(root->right);
  printRightBoundry(root->right);
}

int main()
{
  Node *root = createTree();

  boundryTraversal(root);

  return 0;
}