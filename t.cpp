#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <iterator>

using namespace std;


void
mapExample()
{
    int arr[] = {10,20,30,11,12,13,31,21,31,10,11,11,13};
    map<int, int> memorize;

    for (int i : arr)
    {
        memorize[i]++;
    }

    memorize.insert(pair<int, int> (10, 11));
    memorize.insert(pair<int, int> (10, 13));
    memorize.insert(pair<int, int> (100, 12));
    memorize[10] = 78;
    memorize.insert({101, 12});

    cout << "key " << "     " << "value" << endl; 
    for (map<int,int>::iterator it = memorize.begin() ;it != memorize.end(); it++)
    {
        cout << it->first << "      " << it->second << endl;
    }

    cout << endl;
    cout << endl;
    for (map<int,int>::iterator it = memorize.find(10) ;it != memorize.end(); it++)
    {
        cout << it->first << "      " << it->second << endl;
    }
}

int 
main()
{
    mapExample();
    return 0;
}
