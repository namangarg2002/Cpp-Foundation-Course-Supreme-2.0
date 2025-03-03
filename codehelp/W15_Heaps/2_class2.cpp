#include <iostream>
#include <queue>
#include <climits>
#include <vector>

using namespace std;

struct Node
{
  int data;
  Node *left;
  Node *right;
  Node(int val) : data(val), left(NULL), right(NULL) {}
};

int getKthSmallestElement(int arr[], int n, int k)
{
  priority_queue<int> pq;
  // first k element ko process karo
  for (int i = 1; i <= k; i++)
  {
    int element = arr[i];
    pq.push(element);
  }
  // remaining element ko tabhi insert karenge jab wo raat se chote honge
  for (int i = k + 1; i <= n; i++)
  {
    int element = arr[i];
    if (element < pq.top())
    {
      pq.pop();
      pq.push(element);
    }
  }
  int ans = pq.top();

  return ans;
}

class Info
{
public:
  int maxVal;
  bool isHeap;
  Info(int a, bool b)
  {
    this->maxVal = a;
    this->isHeap = b;
  }
};

Info checkMaxHeap(Node *root)
{
  // base case
  if (root == NULL)
  {
    return Info(INT_MIN, true);
  }
  if (root->left == NULL && root->right == NULL)
  {
    return Info(root->data, true);
  }

  Info leftAns = checkMaxHeap(root->left);
  Info rightAns = checkMaxHeap(root->right);

  // 1 case solve karna hai
  if (root->data > leftAns.maxVal && root->data > rightAns.maxVal && leftAns.isHeap && rightAns.isHeap)
  {
    return Info(root->data, true);
  }
  else
  {
    return Info(max(root->data, max(leftAns.maxVal, rightAns.maxVal)), false);
  }
}

// Convert BST to valid Heap

Node *insertBST(Node *root, int val)
{
  if (root == NULL)
  {
    return new Node(val);
  }
  if (val < root->data)
  {
    root->left = insertBST(root->left, val);
  }
  else
  {
    root->right = insertBST(root->right, val);
  }
  return root;
}

void levelOrderTraversal(Node *root)
{
  if (root == NULL)
    return;

  queue<Node *> q; // Queue to process nodes level by level
  q.push(root);

  while (!q.empty())
  {
    int levelSize = q.size(); // Number of nodes in the current level

    for (int i = 0; i < levelSize; i++)
    {
      Node *current = q.front();
      q.pop();

      cout << current->data << " ";

      if (current->left != NULL)
        q.push(current->left);
      if (current->right != NULL)
        q.push(current->right);
    }
    cout << endl;
  }
}

void storeInOrderTraversal(Node *root, vector<int> &inOrder)
{
  if (root == NULL)
    return;

  // LNR
  storeInOrderTraversal(root->left, inOrder);
  inOrder.push_back(root->data);
  storeInOrderTraversal(root->right, inOrder);
}
void replaceUsingPostOrder(Node *root, vector<int> InOrder, int &index)
{
  if (root == NULL)
    return;

  // LRN
  replaceUsingPostOrder(root->left, InOrder, index);
  replaceUsingPostOrder(root->right, InOrder, index);
  // N
  root->data = InOrder[index++];
}
void convertBSTIntoMaxHeap(Node *root)
{
  // 1 Step: store inOrder
  vector<int> inOrder;
  storeInOrderTraversal(root, inOrder);
  // replace the node values with the sorted inorder values , usinf post Order traversal
  int index = 0;
  replaceUsingPostOrder(root, inOrder, index);
}

int main()
{
  // //  Creation max-Heap(default)
  // priority_queue<int> pq;

  // // Insertion
  // pq.push(10);
  // pq.push(20);
  // pq.push(30);
  // pq.push(40);
  // pq.push(50);

  // // top Element i.e., ROOT Element
  // cout << "Top element of Heap: " << pq.top() << endl;

  // // pop(deleltion) always from top;
  // pq.pop();
  // cout << "Top element of Heap: " << pq.top() << endl;

  // // size of Heap
  // cout << "Size of max Heap: " << pq.size()<<endl;

  // // empty or not
  // if (pq.empty())
  // {
  //   cout << "Empty" << endl;
  // }
  // else
  // {
  //   cout << "Not Empty" << endl;
  // }

  // // Min-Heap Creation
  // priority_queue<int, vector<int>, greater<int>> pq;

  // // insert in Min-Heap
  // pq.push(100);
  // pq.push(90);
  // pq.push(70);

  // // top ELement in Min-Heap
  // cout << "Top element of Min-Heap: " << pq.top() << endl;

  // pq.pop();
  // cout << "Top element of Min-Heap: " << pq.top() << endl;

  // cout << "Size of Min-Heap: " << pq.size() << endl;

  // int arr[] = {-1, 3, 7, 4, 5, 6, 8, 9};
  // int n = 7;
  // int k = 5;

  // cout << "Kth Smallest number is: " << getKthSmallestElement(arr, n, k) << endl;

  vector<int> bstValues = {100, 50, 150, 40, 60, 110, 200, 20};
  Node *root = NULL;

  // Build BST
  for (int val : bstValues)
  {
    root = insertBST(root, val);
  }
  cout << "Printing the BST: " << endl;
  levelOrderTraversal(root);
  cout << endl;

  cout << "Converting Into Heap: " << endl;

  convertBSTIntoMaxHeap(root);
  cout << "Printing the Heap: " << endl;
  levelOrderTraversal(root);

  return 0;
}