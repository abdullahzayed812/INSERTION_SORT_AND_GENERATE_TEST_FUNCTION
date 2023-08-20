#include <iostream>
#include <algorithm>
#include <assert.h>

using namespace std;

void insertionSort(int arr[], int size);
void printArray(int arr[], int size);
void testSort();

void insertionSort(int arr[], int size)
{
  for (int i = 1; i < size; i++)
  {
    int copy = arr[i];
    int j = i - 1;

    for (; j >= 0; j--)
    {
      if (arr[j] < copy)
        break;
      arr[j + 1] = arr[j]; // Shift item one step
    }
    arr[j + 1] = copy;
  }
}

void printArray(int arr[], int size)
{
  for (int i = 0; i < size; i++)
    cout << "Index " << i << " => " << arr[i] << "\n";
}

void testSort()
{
  const int SIZE = 5;
  int arr[SIZE], copy[SIZE], temp[SIZE];

  for (int test = 0; test < 1000; test++)
  {
    cout << "TEST " << test + 1 << " " << flush;

    for (int i = 0; i < SIZE; i++)
      arr[i] = copy[i] = temp[i] = rand() % 100;

    insertionSort(arr, SIZE);

    sort(copy, copy + SIZE);

    bool passed = true;
    for (int i = 0; i < SIZE; i++)
      passed &= (arr[i] == copy[i]);

    if (!passed)
    {
      for (int i = 0; i < SIZE; i++)
        cout << temp[i] << " " << flush;

      assert(false);
    }
  }
}

int main()
{
  const int SIZE = 5;
  int arr[SIZE] = {29, 10, 14, 37, 13};

  // printArray(arr, SIZE);

  // insertionSort(arr, SIZE);

  // printArray(arr, SIZE);

  testSort();

  return 0;
}