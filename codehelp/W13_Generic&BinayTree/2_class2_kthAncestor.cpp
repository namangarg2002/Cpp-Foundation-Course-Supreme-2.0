// KthAncestor of a Node in Binary Tree

#include <iostream>
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
  cout << "enter the value for Node: " << endl;
  int data;
  cin >> data;
  if (data == -1)
  {
    return NULL;
  }
  Node *root = new Node(data);

  root->left = createTree();

  root->right = createTree();

  return root;
}

Node *findKthAncestor(Node *root, int node, int &k)
{
  if (root == NULL)
    return NULL;

  if (root->data == node)
  {
    return root;
  }

  Node *left = findKthAncestor(root->left, node, k);
  Node *right = findKthAncestor(root->right, node, k);

  if (left != NULL || right != NULL)
  {
    k--;

    if (k == 0)
    {
      return root;
    }

    return (right != NULL) ? right : left;
  }

  return NULL;
}

int kthAncestor(Node *root, int k, int node)
{
  Node *ancestor = findKthAncestor(root, node, k);

  if (k > 0 || ancestor == nullptr || ancestor->data == node)
  {
    return -1;
  }

  return ancestor->data;
}

int main()
{
  Node *root = createTree();

  int k = 2;
  int node = 80;

  int ancestor = kthAncestor(root, k, node);
  if (ancestor != -1)
  {
    cout << "The " << k << "th ancestor of node " << node << " is: " << ancestor << endl;
  }
  else
  {
    cout << "The " << k << "th ancestor of node " << node << " doesn't exist." << endl;
  }
  return 0;
}