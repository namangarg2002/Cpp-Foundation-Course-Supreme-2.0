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

void printRightView(Node *root, int level, vector<int> &rightView)
{
  if (root == NULL)
    return;

  if (level == rightView.size())
  {
    // iska matlab left view ki node milgai h, store karo element ko
    rightView.push_back(root->data);
  }
  printRightView(root->right, level + 1, rightView);
  printRightView(root->left, level + 1, rightView);
}

int main()
{
  Node *root = createTree();
  vector<int> v;

  printRightView(root, 0, v);
  cout << endl;
  cout << "Right Side View of Tree: ";
  for (int val : v)
  {
    cout << val << " ";
  }
  cout << endl;

  return 0;
}