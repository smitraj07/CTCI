#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <string>
#include <vector>

using namespace std;

// Finds if s1 is substring of s2
bool 
isSubstring(const string &s1, const string &s2)
{
    if ((s1.length() > s2.length()) || (s1.length() == 0 || s2.length() == 0))
        return false;

    const char *ch1 = s1.c_str();
    const char *ch2 = s2.c_str();

    while (*ch2 != '\0')
    {
        while ((*ch1 == *ch2) && (*ch1 != '\0' && *ch2 != '\0'))
        {
            ch1++;
            ch2++;
        }
        if (*ch1 == '\0')
        {
            break;
        }
        if (ch1 == s1.c_str())
            ch2++;
        else
            ch1 = s1.c_str();
    }
    if (*ch1 != '\0')
        return false;

    return true;
}

// only one call to isSubstring to identify s2 is a rotation of s1
bool
isRotateSubstring(string &s1, string &s2)
{
    string ss1 = s1 + s1;
    return isSubstring(s2, ss1);
}

int 
main()
{
    string s1 = "its";
    string s2 = "smit";
    if (isRotateSubstring(s1, s2))
        cout << "Yes " << endl;
    else
    {
        cout << "No " << endl;
    }
    
    return 0;
}