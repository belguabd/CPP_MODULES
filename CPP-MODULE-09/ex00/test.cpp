#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

int main()
{
    map <string, int> mp;
    for (int i = 0; i < 4; i++) {
        mp["test"] = i;
        cout << i * 2 << ": " << i << endl;
    }

    map<string, int>::iterator a = mp.lower_bound("a");
    if (a == mp.end())
        cout << "END" << endl;
    else
        cout << "Res: " << a->second << endl;
}