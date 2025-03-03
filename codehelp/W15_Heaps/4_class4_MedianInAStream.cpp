#include <iostream>
#include <queue>
#include <vector>
using namespace std;

void solveForMedian(double &median, priority_queue<int> &maxHeap, priority_queue<int, vector<int>, greater<int>> &minHeap, int element)
{

  // maxHeap and minHeap has same size
  if (maxHeap.size() == minHeap.size())
  {
    if (element > median)
    {
      minHeap.push(element);
      median = minHeap.top();
    }
    else
    {
      maxHeap.push(element);
      median = maxHeap.top();
    }
  }

  // maxHeap size = minHeap size + 1
  else if (maxHeap.size() == minHeap.size() + 1)
  {
    if (element > median)
    {
      minHeap.push(element);
    }
    else
    {
      int maxTop = maxHeap.top();
      maxHeap.pop();
      minHeap.push(maxTop);
      maxHeap.push(element);
    }
    median = (minHeap.top() + maxHeap.top()) / 2.0;
  }
  // minHeap size = maxHeap size + 1
  else if (minHeap.size() == maxHeap.size() + 1)
  {
    if (element > median)
    {
      int minTop = minHeap.top();
      minHeap.pop();
      maxHeap.push(minTop);
      minHeap.push(element);
    }
    else
    {
      maxHeap.push(element);
    }
    median = (minHeap.top() + maxHeap.top()) / 2.0;
  }
}

int main()
{
  int arr[] = {12, 10, 8, 4, 2, 3, 15};
  int n = 7;

  //12 -> 12
  //10 12 -> 11
  //8 10 12 -> 10
  //4 8 10 12 -> 9
  //2 4 8 10 12 -> 8
  //2 3 4 8 10 12 0 -> 6
  //2 3 4 8 10 12 15 -> 8

  double median = 0;
  priority_queue<int> maxHeap;
  priority_queue<int, vector<int>, greater<int>> minHeap;

  for (int i = 0; i < n; i++)
  {
    int element = arr[i];
    solveForMedian(median, maxHeap, minHeap, element);
    cout << "Median found: " << median << endl;
  }

  return 0;
}