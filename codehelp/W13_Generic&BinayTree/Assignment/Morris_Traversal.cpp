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

// Function to create the binary tree
Node *createTree()
{
  cout << "Enter the value for Node: " << endl;
  int data;
  cin >> data;
  if (data == -1)
  {
    return NULL;
  }
  // Step1: create Node
  Node *root = new Node(data);

  // Step2: Create left Subtree
  root->left = createTree();

  // Step3: Create right Subtree
  root->right = createTree();

  return root;
}

// Morris Inorder Traversal (Iterative and Space-Optimized)
void morrisTraversal(Node *root)
{
  Node *curr = root;
  while (curr != NULL)
  {
    if (curr->left == NULL)
    {
      // Visit the node if left child doesn't exist
      cout << curr->data << " ";
      curr = curr->right;
    }
    else
    {
      // Find the inorder predecessor of curr
      Node *pred = curr->left;
      while (pred->right != NULL && pred->right != curr)
      {
        pred = pred->right;
      }

      if (pred->right == NULL)
      {
        // Establish thread (temporary link from predecessor to curr)
        pred->right = curr;
        curr = curr->left;
      }
      else
      {
        // Thread exists, remove the link and visit the node
        pred->right = NULL;
        cout << curr->data << " ";
        curr = curr->right;
      }
    }
  }
}

int main()
{
  Node *root = createTree();

  cout << "Morris InOrder: ";
  morrisTraversal(root);
  cout << endl;

  return 0;
}
