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

set<int> s1, s2;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int num;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        s1.insert(num);
    }
    int m;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> num;
        s2.insert(num);
    }

    set<int> s;
    for (auto i : s1)
    {
        if (s2.find(i) != s2.end())
        {
            s.insert(i);
        }
    }

    for (auto i : s)
    {
        cout << i << " ";
    }
    return 0;
}