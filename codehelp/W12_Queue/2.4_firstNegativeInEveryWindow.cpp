#include <iostream>
#include <deque>
using namespace std;

void printFirstNegtive(int *arr, int n, int k)
{
  deque<int> dq;

  // Step 1: procees first K element - first window
  for (int index = 0; index < k; index++)
  {
    int element = arr[index];
    if (element < 0)
    {
      dq.push_back(index);
    }
  }

  // Step 2: process remaining windows -> removal of old element and addition of new element
  for (int index = k; index < n; index++)
  {

    if (dq.empty())
    {
      cout << "0 ";
    }
    else
    {
      cout << arr[dq.front()] << " ";
    }

    // removal - jo bhi index out of range h, usko queue m se remove krdo
    if (!dq.empty() && dq.front() <= index - k)
    {
      dq.pop_front();
    }

    // addition
    if (arr[index] < 0)
    {
      dq.push_back(index);
    }
  }

  // last window answer print kardo
  if (dq.empty())
  {
    cout << "0 " << endl;
  }
  else
  {
    cout << arr[dq.front()] << " ";
  }
}

int main()
{
  int arr[] = {2, -5, 4, -1, -2, 0, 5};
  int k = 3;
  int n = 7;

  printFirstNegtive(arr, n, k);

  return 0;
}