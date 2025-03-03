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

Node *minValue(Node *root)
{
  if (root == NULL)
  {
    return NULL;
  }
  Node *temp = root;
  while (temp->left != NULL)
  {
    temp = temp->left;
  }
  return temp;
}

Node *maxValue(Node *root)
{
  if (root == NULL)
  {
    return NULL;
  }
  Node *temp = root;
  while (temp->right != NULL)
  {
    temp = temp->right;
  }
  return temp;
}

Node *deleteFromBST(Node *root, int target)
{
  if (root == NULL)
  {
    return NULL;
  }
  // target ko dundho
  if (root->data == target)
  {
    // target ko delete karo
    // 4 cases:

    // case 1: both leftside and rightside are NULL(leaf node)
    if (root->left == NULL && root->right == NULL)
    {
      delete root;
      return NULL;
    }

    // case 2: leftSide is nonNULL and rightSide is NULL
    if (root->left != NULL && root->right == NULL)
    {
      Node *childSubTree = root->left;
      delete root;
      return childSubTree;
    }

    // case 3: leftSide is NULL and rightSide is nonNULL
    if (root->left == NULL && root->right != NULL)
    {
      Node *childSubTree = root->right;
      delete root;
      return childSubTree;
    }

    // case 4: leftSide is nonNULL and rightSide is nonNULL
    else
    {
      // M1: LSubTree MaxVal;
      Node *maxi = maxValue(root->left);
      // data replacement
      root->data = maxi->data;
      // removing actual maxi
      root->left = deleteFromBST(root->left, maxi->data);
      return root;

      // // M2: RSubTree MinVal;
      // Node *mini = minValue(root->right);
      // // data replacement
      // root->data = mini->data;
      // // removing actual maxi
      // root->right = deleteFromBST(root->right, mini->data);
      // return root;
    }
  }
  else if (root->data > target)
  {
    // left mai jao
    root->left = deleteFromBST(root->left, target);
    return root;
  }
  else
  {
    // right mai jao
    root->right = deleteFromBST(root->right, target);
    return root;
  }
}

int main()
{
  Node *root = NULL;
  createBST(root);
  cout << "Before deletion: " << endl;
  levelOrderTraversal(root);

  deleteFromBST(root, 100);
  cout << "After deletion: " << endl;
  levelOrderTraversal(root);

  return 0;
}