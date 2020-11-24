// leetcode submission
// https://leetcode.com/problems/set-matrix-zeroes/

#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <string>
#include <vector>

using namespace std;


class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix);
    void zeroOut(vector<vector<int>>& matrix, int i, int j);
};

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


void
Solution::setZeroes(vector<vector<int>>& matrix)
{
    bool column = 1;
    for (int i = 0 ;i < matrix.size(); i++)
    {
        if(matrix[i][0] == 0)
        {
            column = 0;
            break;
        }
    }
    
    bool row = 1;
    for (int i = 0 ;i < matrix[0].size(); i++)
    {
        if(matrix[0][i] == 0)
        {
            row = 0;
            break;
        }   
    }
    
    for (int i = 1 ;i < matrix.size(); i++)
    {
        for (int j = 1 ;j < matrix[i].size(); j++)
        {
            if (matrix[i][j] == 0)
            {
                matrix[0][j] = 0;
                matrix[i][0] = 0;
            }
        }
    }
    
    for (int i = 1 ;i < matrix.size();i++)
    {
        for (int j = 1; j < matrix[i].size(); j++)
        {
            if ((matrix[i][0] == 0) || (matrix[0][j] == 0))
                matrix[i][j] = 0;
        }
    }
    
    for (int i = 0 ;(row == 0) && (i < matrix[0].size()); i++)
    {
        
        matrix[0][i] = 0;
    }
    
    for (int i = 0 ;(column == 0) && (i < matrix.size()); i++)
    {
        matrix[i][0] = 0;
    }   
}

int main()
{
    vector<vector<int>> v = { {1,1,1},\
                              {1,0,1},\
                              {1,1,1}\
                            };
    printArray<int>(v);
    Solution S;
    S.setZeroes(v);
    printArray<int>(v);

    return 0;
}