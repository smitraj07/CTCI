#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <string>

using namespace std;

bool isCompressionPossible(const string &s)
{
    int stringLength = s.length();
    int minCompressLength = 0;
    const char *str = s.c_str();
    const char *newChar = str;

    while (*str)
    {
        minCompressLength +=2;
        while (*newChar == *str)
        {
            str++;
        }
        newChar = str;
    }

    if (stringLength < minCompressLength)
        return false;
    
    return true;
}

const string &compress(const string &str)
{
    if(isCompressionPossible(str) == false)
        return str;

    string *compressed = new string();
    char prevChar = str[0];
    int i = 0;
    while ( i < str.length())
    {
        int count = 0;
        while (str[i] == prevChar && i < str.length())
        {
            count++;
            i++;
        }
        compressed->push_back(prevChar);
        compressed->append(to_string(count));
        prevChar = str[i];
    }
    return *compressed;
}

int main() 
{ 
    string s1 = "bcbcaaaaaaaaaaaaaaababa";
    string compressed = compress(s1);
    cout << compressed << endl;

    return 0; 
} 