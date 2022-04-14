#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <algorithm>
#include <utility>
#include <cmath>
#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <list>
#include <deque>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <queue>

using ll = long long;
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string str;
    cin >> str;
    string c = "";
    string h = "";

    bool c_start = false;
    bool h_start = false;

    for (char i : str)
    {
        if (i == 'C')
        {
            c_start = true;
            continue;
        }
        if (i == 'H')
        {
            c_start = false;
            h_start = true;
            continue;
        }
        if (c_start == true)
        {
            c.push_back(i);
        }        
        if (h_start == true)
        {
            h.push_back(i);
        }
    }

    if (c == "")
    {
        c += '1';
    }
    if (h == "")
    {
        h += '1';
    }
    cout << stoi(c) * 12 + stoi(h);

    return 0;
}