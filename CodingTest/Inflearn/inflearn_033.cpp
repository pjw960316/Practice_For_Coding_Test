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

set<int> v;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,num;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        v.insert(num);
    }
    int cnt = 0;
    for (auto i = v.end(); i != v.begin(); i--)
    {
        if (cnt == 3)
        {
            cout << *i;
            return 0;
        }
        cnt++;
    }
    return 0;
}