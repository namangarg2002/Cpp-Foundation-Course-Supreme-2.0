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

void bottomView(Node *root)
{
  map<int, int> hdToNodemap;
  queue<pair<Node *, int>> q;
  q.push({root, 0});

  while (!q.empty())
  {
    auto &temp = q.front();
    q.pop();

    Node *frontNode = temp.first;
    int hd = temp.second;

    hdToNodemap[hd] = frontNode->data;
    // child ko dekhna hai
    if (frontNode->left != NULL)
    {
      q.push({frontNode->left, hd - 1});
    }
    if (frontNode->right != NULL)
    {
      q.push({frontNode->right, hd + 1});
    }
  }
  cout << endl;
  cout << "printing bottom view: " << endl;
  for (auto i : hdToNodemap)
  {
    cout << i.second << " ";
  }
}

int main()
{
  Node *root = createTree();

  bottomView(root);


  return 0;
}