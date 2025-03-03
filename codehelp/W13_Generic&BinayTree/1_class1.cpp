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

// it returns root node of the crested tree
Node *createTree()
{
  cout << "enter the value for Node: " << endl;
  int data;
  cin >> data;
  if (data == -1)
  {
    return NULL;
  }
  // Step1: create Node
  Node *root = new Node(data);

  // Step2: Create left Subtree
  // cout << "left of Node: " << root->data << endl;
  root->left = createTree();

  // Step3: Create right Subtree
  // cout << "right of Node: " << root->data << endl;
  root->right = createTree();

  return root;
}

void preOrderTraversal(Node *root)
{
  // base case:
  if (root == NULL)
  {
    return;
  }
  // N L R
  // N
  cout << root->data << " ";
  // L
  preOrderTraversal(root->left);
  // R
  preOrderTraversal(root->right);
}

void inOrderTraversal(Node *root)
{
  // base case:
  if (root == NULL)
  {
    return;
  }
  // L N R
  // L
  inOrderTraversal(root->left);
  // N
  cout << root->data << " ";
  // R
  inOrderTraversal(root->right);
}

void postOrderTraversal(Node *root)
{
  // base case
  if (root == NULL)
  {
    return;
  }
  // L R N
  // L
  postOrderTraversal(root->left);
  // R
  postOrderTraversal(root->right);
  // N
  cout << root->data << " ";
}

void levelOrderTraversal(Node *root)
{
  queue<Node *> q;
  q.push(root);

  // main traversal
  while (!q.empty())
  {
    Node *front = q.front();
    q.pop();
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

void modifiedLevelOrderTraversal(Node *root)
{
  if (root == NULL)
    return;
  queue<Node *> q;
  q.push(root);
  q.push(NULL);

  while (q.size() > 1)
  {
    Node *front = q.front();
    q.pop();

    if (front == NULL)
    {
      cout << endl;
      q.push(NULL);
    }
    else
    {
      // valid Case
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

int main()
{
  Node *root = createTree();

  // cout << "PreOrder: ";
  // preOrderTraversal(root);
  // cout << endl;

  // cout << "InOrder: ";
  // inOrderTraversal(root);
  // cout << endl;

  // cout << "PostOrder: ";
  // postOrderTraversal(root);
  // cout << endl;

  cout << "LevelOrder: ";
  levelOrderTraversal(root);
  cout << endl;

  // cout << "MofifiedLevelOrder: ";
  // modifiedLevelOrderTraversal(root);
  cout << endl;

  return 0;
}