#include "Array_Is_Sorted.h"
#include <iostream>
using namespace std;

bool isDec(int *arr, int size)
{
    for (int i = 0; i < size - 1; ++i)
        if (arr[i] < arr[i + 1]) return false;
    return true;
}

bool isInc(int *arr, int size)
{
    for (int i = 0; i < size - 1; ++i)
        if (arr[i] > arr[i + 1]) return false;
    return true;
}

bool isSorted(int *arr, int size)
{
    // for (int i = 0; i < size; ++i)
    // {
    //     cout << arr[i] << " ";
    // }
    // cout << endl;
    if(size == 1)
    {
        //base case
        return true;
    }
    if (*arr > *(arr + 1)) return isDec(arr, size);
    if (*arr < * (arr + 1)) return isInc(arr, size);
    if (*arr == *(arr+1)) return isSorted(arr+1,size-1);
    return false;
}
int main()
{
    int down[6] = {5, 4, 3, 2, 1, 0};
    int up[6] = {0, 1, 2, 3, 4, 5};
    int jumbled[6] = {3, 6, 2, 0, 1, 99};
    int dupes1[6] = {5,5,5,3,7,1};
    int dupes2[6] = {5,5,5,5,5,5};
    cout << boolalpha << isSorted(down, 6) << endl;
    cout << boolalpha << isSorted(up, 6) << endl;
    cout << boolalpha << isSorted(jumbled, 6) << endl;
    cout << boolalpha << isSorted(dupes1, 6) << endl;
    cout << boolalpha << isSorted(dupes2, 6) << endl;
}
