#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;

bool editPossible(const string &s1, const string &s2)
{
    if (abs(int(s1.length() - s2.length())) > 1)
        return false;

    unsigned int arr[128] = {0};
    const char *str1 = s1.c_str();
    const char *str2 = s2.c_str();

    while (*str1 || *str2)
    {
        if (*str1)
            arr[int(*str1)]++;
        if (*str2)
            arr[int(*str2)]--;
        str1++;
        str2++;
    }

    // Following valid values:
    // all 0s (no edit), at most one 1 (one insert), 
    // at most one -1 (one delete)
    // at most one tuple of <1,-1> (one update)
    int flag1 = 0;
    int flag2 = 0;
    for (int i : arr)
    {
        if (abs(i) > 1)
            return false;
        if (i == 1)
            flag1++;
        else if (i == -1)
            flag2--;
        else
        {
            // Do nothing
        }
        
        if (flag1 > 1 || flag2 < -1)
            return false;
    }
    return true;
}

int main() 
{ 
    string s1 = "pale";
    string s2 = "ple";
    if(editPossible(s1, s2))
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    
    return 0; 
} 