#include <iostream>
#include <queue>
#include<vector>
using namespace std;

class Info
{
public:
  int data;
  int rowIndex;
  int colIndex;

  Info(int val, int rIndex, int cIndex)
  {
    this->data = val;
    this->rowIndex = rIndex;
    this->colIndex = cIndex;
  }
};

class compare
{
public:
  bool operator()(Info *a, Info *b)
  {
    return a->data > b->data;
  }
};

void mergeKSortedArrays(int arr[][4], int n, int k, vector<int> &ans)
{
  priority_queue<Info *, vector<Info *>, compare> pq;

  // Step 1: process first element of K arrays
  for (int row = 0; row < k; row++)
  {
    int element = arr[row][0]; // it will fetch first element of each row 
    Info *temp = new Info(element, row, 0);
    pq.push(temp);
  }
  while (!pq.empty())
  {
    Info *temp = pq.top();
    pq.pop();
    int topData = temp->data;
    int topRow = temp->rowIndex;
    int topCol = temp->colIndex;

    // Step 2: store in the answer
    ans.push_back(topData);
    // Step 3: fetch next elemnt of same row of topData which we have to insert ans also check whether next element is vailable or not
    if (topCol + 1 < n)
    {
      // that means there are some element available in that row
      Info *newInfo = new Info(arr[topRow][topCol + 1], topRow, topCol + 1);
      pq.push(newInfo);
    }
  }
}

int main()
{
  // Merge K Sorted Array
  // int arr[3][4] = {
  //     {1, 4, 8, 10},
  //     {2, 3, 6, 9},
  //     {5, 7, 11, 12}
  // };

  // int n = 4;
  // int k = 3;

  // vector<int> ans;
  // mergeKSortedArrays(arr, n, k, ans);
  // cout << "Printing ans Array: " << endl;
  // for (int i = 0; i < ans.size(); i++)
  // {
  //   cout << ans[i] << " ";
  // }
  // cout << endl;
  return 0;
}