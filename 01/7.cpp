#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <string>
#include <vector>

using namespace std;

template <typename T>
void 
printArray(const vector<vector<T>> &arr)
{
    for (vector<T> i: arr)
    {
        for (T j: i)
        {
            cout << j << " ";        
        }
        cout << endl;
    }
}

template <typename T>
void
rotate90degree(vector<vector<T>> &arr)
{
    // Mirror image along iverted diagonal of matrix
    for (int i = 0 ;i < arr.size(); i++)
    {
        for (int j = i+1 ;j < arr[i].size() ; j++)
        {
            T temp;
            temp = arr[i][j];
            arr[i][j] = arr[j][i];
            arr[j][i] = temp;
        }
    }

    // // take mirror image along X axis of matrix
    for (int i = 0 ;i < arr.size(); i++)
    {
        int lastIndex = arr[i].size() - 1;
        int firstIndex = 0;
        while (lastIndex > firstIndex)
        {
            T temp;
            temp = arr[i][firstIndex];
            arr[i][firstIndex] = arr[i][lastIndex];
            arr[i][lastIndex] = temp;
            lastIndex--;
            firstIndex++;
        }
    }
}


int main()
{
    vector<vector<int>> arr = {{1, 2, 3},\
                               {4, 5, 6},\
                               {7, 8, 9}};
    printArray<int>(arr);
    rotate90degree<int>(arr);
    cout << endl;
    printArray<int>(arr);
    return 0;
}