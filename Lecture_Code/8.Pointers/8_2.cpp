// ============================================
// Pointers (p. 61)
#include <iostream>
using namespace std;

void print1D(int* arr, int n)
{
  for(int i = 0; i < n; i++)
    cout << arr[i] << " ";
  cout << "\n";
}

void print(int** arr, int r)
{
  for(int i = 0; i < r; i++)
  {
    print1D(arr[i], i + 1);
  }
}

int main()
{
  int r = 3;
  int** array = new int*[r];
  for(int i = 0; i < r; i++)
  {
    array[i] = new int[i + 1];
    for(int j = 0; j <= i; j++)
      array[i][j] = j + 1;
  }
  print(array, r); // later
  // some delete statements
  return 0;	
}