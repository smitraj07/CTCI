#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>

using namespace std;

bool palindromePossible(const string &s)
{
    if (s.size() == 0)
        return true;
    unsigned int arr[128] = {0};
    for(char i : s)
    {
        if (i != ' ')
            arr[int(i)]++;
    }
    
    int oddCount = 0;
    for (int i : arr)
    {
        if (i%2 != 0)
            oddCount++;
        if (oddCount > 2)
            return false;
    }
    return true;
}

int main() 
{ 
    string s = "tact gaa ggco";
    if(palindromePossible(s))
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    
    return 0; 
} 