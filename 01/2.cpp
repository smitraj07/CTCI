#include <iostream>
#include <cstdlib>
#include <cstdio>

using namespace std;

bool isPermut(const string &str1, const string &str2)
{
    if (str1.length() != str2.length())
        return false;
    
    const char *s1 = str1.c_str();
    const char *s2 = str2.c_str();
    int arr[128] = {0};

    while (*s1 != '\0')
    {
        arr[int(*s1)]++;
        arr[int(*s2)]--;
        s1++;
        s2++;
    }

    for (int i : arr)
    {
        if (i != 0)
            return false;
    }
    return true;
}

int main() 
{ 
    string s = "smit raj";
    string p = "it s jar"; 
    if (isPermut(s, p)) 
        cout << "Yes" << endl; 
    else
        cout << "No" << endl; 
    return 0; 
} 