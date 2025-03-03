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

Node *insertIntoBST(Node *root, int data)
{
  if (root == NULL)
  {
    return new Node(data);
  }

  // it's not thr first node
  if (data > root->data)
  {
    root->right = insertIntoBST(root->right, data);
  }
  else
  {
    root->left = insertIntoBST(root->left, data);
  }
  return root;
}

void createBST(Node *&root)
{
  cout << "Enter root data: ";
  int data;
  cin >> data;

  while (data != -1)
  {
    root = insertIntoBST(root, data);
    cout << "Enter data: ";
    cin >> data;
  }
}

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

void preOrder(Node *root)
{
  // NLR
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
  // LNR
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
  // LRN
  if (root == NULL)
  {
    return;
  }
  postOrder(root->left);
  postOrder(root->right);
  cout << root->data << " ";
}

int minValue(Node *root)
{
  if (root == NULL)
  {
    cout << "No Min Value" << endl;
    return -1;
  }
  Node *temp = root;
  while (temp->left != NULL)
  {
    temp = temp->left;
  }
  return temp->data;
}

int maxValue(Node *root)
{
  if (root == NULL)
  {
    cout << "No Max Value" << endl;
    return -1;
  }
  Node *temp = root;
  while (temp->right != NULL)
  {
    temp = temp->right;
  }
  return temp->data;
}

bool searchInBST(Node *root, int target)
{
  // base case
  if (root == NULL)
  {
    return false;
  }
  // 1 case solve
  if (root->data == target)
  {
    return true;
  }
  // recursion will handle it further
  // left or right
  bool leftAns = false;
  bool rightAns = false;
  if (target > root->data)
  {
    // right side (Maximum)
    rightAns = searchInBST(root->right, target);
  }
  else
  {
    // left side (Minimum)
    leftAns = searchInBST(root->left, target);
  }
  return leftAns || rightAns;
}

int main()
{
  Node *root = NULL;
  createBST(root);

  // levelOrderTraversal(root);

  // preOrder(root);
  // cout << endl;
  // inOrder(root);
  // cout << endl;
  // postOrder(root);

  // cout << minValue(root) << endl;
  // cout << maxValue(root) << endl;

  bool ans = searchInBST(root, 20);
  ans == true ? cout << "Found" : cout << "Not Found";

  return 0;
}