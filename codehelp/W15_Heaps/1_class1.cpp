#include <iostream>
using namespace std;

class Heap
{
public:
  int *arr;
  int capacity;
  int size;

  Heap(int capacity)
  {
    this->arr = new int[capacity];
    this->capacity = capacity;
    // size = current number of elements in heap
    this->size = 0;
  }

  void insert(int val)
  {
    if (size == capacity)
    {
      cout << "heap OverFlow" << endl;
      return;
    }
    // size increase kar jaega
    size++;
    int index = size;
    arr[index] = val;

    // take the val to its correcty position
    while (index > 1)
    {
      int parentIndex = index / 2;
      if (arr[index] > arr[parentIndex])
      {
        swap(arr[index], arr[parentIndex]);
        index = parentIndex;
      }
      else
      {
        break;
      }
    }
  }
  int deletion()
  {
    int answer = arr[1];
    // replacement
    arr[1] = arr[size];
    // last elemnt ko delete kardo uski original position se
    size--;

    int index = 1;
    while (index < size)
    {
      int leftIndex = 2 * index;
      int rightIndex = 2 * index + 1;
      // find out theno mai se sabse bada kon hai
      int largestKaIndex = index;
      // check left child
      if (leftIndex <= size && arr[largestKaIndex] < arr[leftIndex])
      {
        largestKaIndex = leftIndex;
      }
      if (rightIndex <= size && arr[largestKaIndex] < arr[rightIndex])
      {
        largestKaIndex = rightIndex;
      }
      // no change
      if (index == largestKaIndex)
      {
        break;
      }
      else
      {
        swap(arr[index], arr[largestKaIndex]);
        index = largestKaIndex;
      }
    }
    return answer;
  }

  void printHeap()
  {
    for (int i = 1; i <= size; i++)
    {
      cout << arr[i] << " ";
    }
  }
};

void heapify(int *arr, int n, int index)
{
  int leftIndex = 2 * index;
  int rightIndex = 2 * index + 1;

  int largestKaIndex = index;

  // theeno mai se max laao
  if (leftIndex <= n && arr[largestKaIndex] < arr[leftIndex])
  {
    largestKaIndex = leftIndex;
  }
  if (rightIndex <= n && arr[largestKaIndex] < arr[rightIndex])
  {
    largestKaIndex = rightIndex;
  }
  // after these condition will pointing towards larget element among 3
  if (index != largestKaIndex)
  {
    swap(arr[index], arr[largestKaIndex]);
    // rest recurssion will handle it
    index = largestKaIndex;
    heapify(arr, n, index);
  }
}

void buildHeap(int arr[], int n)
{
  for (int index = n / 2; index > 0; index--)
  {
    heapify(arr, n, index);
  }
}

void heapSort(int arr[], int n)
{
  int index = 1;
  while (n != 1)
  {
    swap(arr[index], arr[n]);
    n--;
    heapify(arr, n, index);
  }
}

int main()
{
  int arr[] = {-1, 5, 10, 15, 20, 25, 12};
  int n = 6;
  buildHeap(arr, n);

  cout << "Printing Heap: " << endl;
  for (int i = 1; i <= n; i++)
  {
    cout << arr[i] << " ";
  }
  cout << endl;

  heapSort(arr, n);
  cout << "Printing Heap After HeapSort: " << endl;
  for (int i = 1; i <= n; i++)
  {
    cout << arr[i] << " ";
  }
  cout << endl;

  // Heap h(20);
  // // insertion
  // h.insert(5);
  // h.insert(10);
  // h.insert(15);
  // h.insert(6);
  // h.insert(25);
  // h.insert(50);

  // cout << "Printing the content of heap: " << endl;
  // h.printHeap();
  // int ans = h.deletion();
  // cout << endl;
  // cout << ans << endl;
  // h.printHeap();
  // return 0;
}