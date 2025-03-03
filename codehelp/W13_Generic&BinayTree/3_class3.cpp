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

void printLeftSideView(Node *root)
{
  if (root == NULL)
    return;
  queue<Node *> q;
  q.push(root);

  while (!q.empty())
  {
    int levelSide = q.size();

    for (int i = 0; i < levelSide; i++)
    {
      Node *current = q.front();
      q.pop();

      if (i == 0)
      {
        cout << current->data << " ";
      }

      if (current->left)
      {
        q.push(current->left);
      }
      if (current->right)
      {
        q.push(current->right);
      }
    }
  }
  cout << endl;
}

int main()
{
  Node *root = createTree();

  cout << "LeftSideView: ";
  printLeftSideView(root);
  cout << endl;

  return 0;
}