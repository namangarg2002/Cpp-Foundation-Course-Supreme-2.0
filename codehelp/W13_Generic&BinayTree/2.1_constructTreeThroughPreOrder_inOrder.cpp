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

int searchInOrder(int inOrder[], int size, int target)
{
  for (int i = 0; i < size; i++)
  {
    if (inOrder[i] == target)
    {
      return i;
    }
  }
  return -1;
}

Node *constructTreeFromPreAndinordertraversal(int preOrder[], int inOrder[], int &preOrderIndex, int inOrderStart, int inOrderEnd, int size)
{
  // base case
  if (preOrderIndex >= size || inOrderStart > inOrderEnd)
  {
    return NULL;
  }
  // 1 case solve akrta hu
  int element = preOrder[preOrderIndex];
  preOrderIndex++;

  Node *root = new Node(element);
  // search that element in InOrder array that tells us about which element move to to left or right to that element
  int position = searchInOrder(inOrder, size, element);

  // baaki recursion sabhal lega
  root->left = constructTreeFromPreAndinordertraversal(preOrder, inOrder, preOrderIndex, inOrderStart, position - 1, size);

  root->right = constructTreeFromPreAndinordertraversal(preOrder, inOrder, preOrderIndex, position + 1, inOrderEnd, size);

  return root;
}

int main()
{
  int preOrder[] = {2, 8, 10, 6, 4, 12};
  int inOrder[] = {10, 8, 6, 2, 4, 12};

  int size = 6;
  int preOrderIndex = 0;

  Node *root = constructTreeFromPreAndinordertraversal(preOrder, inOrder, preOrderIndex, 0, size - 1, size);

  cout << "LevelOrder traversal of the constructed tree: ";
  cout << endl;
  modifiedLevelOrderTraversal(root);
  cout << endl;

  return 0;
}