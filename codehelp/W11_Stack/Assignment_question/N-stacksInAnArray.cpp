#include <iostream>
using namespace std;

class NStack
{
public:
  int *a, *top, *next;
  int n;        // no. of stacks
  int size;     // size of main array
  int freeSpot; // tells free space in main array

  NStack(int _n, int _s) : n(_n), size(_s)
  {
    freeSpot = 0;
    a = new int[size];
    top = new int[n];
    next = new int[size];

    // initializing top
    for (int i = 0; i < n; i++)
    {
      top[i] = -1;
    }

    // initializing next
    for (int i = 0; i < size; i++)
    {
      if (i == size - 1)
      {
        next[i] = -1;
      }
      else
      {
        next[i] = i + 1;
      }
    }
  }

  // Push X  into nth Stack
  bool push(int X, int m)
  {
    if (freeSpot == -1)
    {
      return false; // stack OverFlow
    }

    // Step 1: index find
    int index = freeSpot;

    // Step 2: Update FreeSpot
    freeSpot = next[index];

    // Step 3: Insert Element
    a[index] = X;

    // Step 4: update next
    next[index] = top[m - 1];

    // Step 5: update top
    top[m - 1] = index;

    return true; // push Sucessfull
  }

  // Pop from nth Stack
  int pop(int m)
  {
    if (top[m - 1] == -1)
    {
      return -1; // Stack UnderFlow
    }

    // Step 1: Update Top
    int index = top[m - 1];

    // Step 2 : Update next
    top[m - 1] = next[index];

    // Step 3 :
    next[index] = freeSpot;

    // Step 4:
    freeSpot = index;

    // Step 5: poped Element
    return a[index];
  }

  ~NStack()
  {
    delete[] a;
    delete[] top;
    delete[] next;
  }
};

int main()
{
  NStack s(3, 6);
  cout << s.push(10, 1) << endl;
  cout << s.push(10, 1) << endl;
  cout << s.push(10, 1) << endl;
  cout << s.push(10, 1) << endl;
  cout << s.push(10, 1) << endl;
  cout << s.push(10, 1) << endl;
  cout << s.push(10, 1) << endl;

  cout << s.pop(1) << endl;

  return 0;
}