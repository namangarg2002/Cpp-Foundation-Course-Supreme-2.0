#include <iostream>
#include <map>
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

// Function for level-order traversal of the tree
void levelOrderTraversal(Node *root)
{
  if (!root)
    return;

  queue<Node *> q;
  q.push(root);

  while (!q.empty())
  {
    Node *current = q.front();
    q.pop();

    cout << current->data << " ";

    if (current->left)
      q.push(current->left);
    if (current->right)
      q.push(current->right);
  }
  cout << endl;
}

// Function to create a mapping from node values to their indices in the inorder traversal
void createMapping(int inOrder[], int size, map<int, int> &valueToIndexMap)
{
  for (int i = 0; i < size; i++)
  {
    valueToIndexMap[inOrder[i]] = i;
  }
}

// Function to construct a tree from postorder and inorder traversal
Node *constructTreeFromPostAndInorderTraversal(
    map<int, int> &valueToIndexMap,
    int postOrder[],
    int inOrder[],
    int &postIndex,
    int inOrderStart,
    int inOrderEnd)
{
  if (postIndex < 0 || inOrderStart > inOrderEnd)
  {
    return NULL;
  }

  // Current root node value
  int element = postOrder[postIndex];
  postIndex--;

  Node *root = new Node(element);

  // Find position of the current element in inorder traversal
  int position = valueToIndexMap[element];

  // Recursive calls
  // Right subtree must be constructed first (postorder traversal property)
  root->right = constructTreeFromPostAndInorderTraversal(valueToIndexMap, postOrder, inOrder, postIndex, position + 1, inOrderEnd);

  // Left subtree
  root->left = constructTreeFromPostAndInorderTraversal(valueToIndexMap, postOrder, inOrder, postIndex, inOrderStart, position - 1);

  return root;
}

int main()
{
  int inOrder[] = {8, 14, 6, 2, 10, 4};
  int postOrder[] = {8, 6, 14, 4, 10, 2};
  int size = 6;
  int postIndex = size - 1;

  map<int, int> valueToIndexMap;
  createMapping(inOrder, size, valueToIndexMap);

  Node *root = constructTreeFromPostAndInorderTraversal(valueToIndexMap, postOrder, inOrder, postIndex, 0, size - 1);

  cout << "Printing the entire tree in level order: " << endl;
  levelOrderTraversal(root);

  return 0;
}
