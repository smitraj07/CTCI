#include <iostream>
#include <cstdlib>
#include <cstdio>

using namespace std;

bool areChractersUnique(const string &str)
{
    int arr[4] = {0};
    int check = 0;
    const char *ch = str.c_str();
    unsigned int max = 0xffffffff;

    while (*ch != '\0')
    {
        int val = 0;
        val = 1 << (int(*ch) % max) + 1;
        if (arr[int(*ch) / max] & val)
        {
            return false;
        }
        arr[int(*ch) / max] = arr[int(*ch) / max] | val;
        ch++;
    }
    return true;
}

int main() 
{ 
    string s = "smit raj smit"; 
    if (areChractersUnique(s)) 
        cout << "Yes" << endl; 
    else
        cout << "No" << endl; 
    return 0; 
} 