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
    int n1 = 0, n2 = 0;
    for (auto i : str)
    {
        if (i == '(')
        {
            n1++;
        }
        else
        {
            n2++;
        }
    }
    if (n1 != n2)
    {
        cout << "NO";
        return 0;
    }

    n1 = 0;
    n2 = 0;

    for (auto i : str)
    {
        if (i == '(')
        {
            n1++;
        }
        else
        {
            n2++;
        }
        if (n1 < n2)
        {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
    return 0;
}