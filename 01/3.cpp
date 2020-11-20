#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>

using namespace std;

void urlify(char *str)
{
    char *last = str;
    char *secondLast;
    bool flag = false;

    while (*last != '\0')
    {
        if (*last == ' ' && flag == false)
        {
            secondLast = last - 1;
            flag = true;
        }
        else if (*last != ' ')
        {
            flag = false;
        }
        last++;
    }
    last--;

    while(*secondLast != *str)
    {
        if(*secondLast == ' ')
        {
            *(last--) = '0';
            *(last--) = '2';
            *(last--) = '%';
            secondLast--;
        }
        *(last--) = *(secondLast--);
    }
}

int main() 
{ 
    char s[] = "Mr John Smith    ";
    urlify(s);
    cout << s << endl;
    return 0; 
} 