#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <string>
#include <vector>

using namespace std;

template <typename T>
T **
create2Darray(int rows, int columns)
{
    T **arr;
    arr = (T **)malloc(sizeof(T *)*rows);

    for (int i = 0 ;i < rows; i++)
    {
        arr[i] = (T *)malloc(sizeof(T)*columns);
    }
    return arr;
}


int 
main()
{
    int **arr;
    arr = create2Darray<int>(3,4);
    arr[1][3] = 4;

    cout << arr[1][3] << endl;
    return 0;
}