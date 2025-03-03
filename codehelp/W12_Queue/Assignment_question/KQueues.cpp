#include <iostream>
#include <queue>
using namespace std;

class KQueue
{
public:
  int n, k, freeSpot;
  int *arr, *front, *rear, *next;

  KQueue(int _n, int _k) : n(_n), k(_k), freeSpot(0)
  {
    arr = new int[n];
    next = new int[n];
    front = new int[k];
    rear = new int[k];
    for (int i = 0; i < k; i++)
    {
      front[i] = rear[i] = -1;
    }
    for (int i = 0; i < n; i++)
    {
      next[i] = i + 1;
    }
    next[n - 1] = -1;
  }

  // push X into Qith Queue
  bool push(int X, int qi)
  {

    // Step1: overflow
    if (freeSpot == -1)
    {
      return false;
    }

    // Step2: find first free index
    int index = freeSpot;

    // Step3: update freeSpot
    freeSpot = next[index];

    // Step4: 1-> if first element in qi
    if (front[qi] == -1)
    {
      front[qi] = index;
    }
    else
    {
      //      2-> link new element to that Q's rearest element
      next[rear[qi]] = index;
    }

    // Step5: Update next
    next[index] = -1;

    // step6: Update rear
    rear[qi] = index;
    arr[index] = X;

    return true;
  }

  // Pop element from qith Queue
  int pop(int qi)
  {
    // Step1: UnderFlow
    if (front[qi] == -1)
    {
      return -1;
    }

    // Step2: find index to pop
    int index = front[qi];

    // Step3: Update Front
    front[qi] = next[index];

    // step4: Update freeSpot
    next[index] = freeSpot;
    freeSpot = index;

    return arr[index];
  }

  ~KQueue()
  {
    delete[] arr;
    delete[] front;
    delete[] rear;
    delete[] next;
  }
};

int main()
{
  KQueue kq(8, 3);
  cout << kq.push(1, 0) << endl;
  cout << kq.push(2, 0) << endl;
  cout << kq.push(5, 1) << endl;
  cout << kq.push(3, 0) << endl;
  cout << kq.pop(1) << endl;
  cout << kq.pop(1) << endl; // underflow at that point

  return 0;
}