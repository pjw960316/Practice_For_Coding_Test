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

struct str
{
    int x1;
    int x2;
    int x3;
};

set<str> s;
set<pair<int,int>> s2;
vector<str> v;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    s2.insert({1,2});
    s2.insert({3,4});
    s2.insert({2,-1});

    for(auto i : s2)
    {
        cout << i.first << " "<<i.second << "\n";
    }
    // s.insert({1,2,3});
    // s.insert({6,5,4});

    // for(auto i : s)
    // {
    //     cout << i.x1 << " " << i.x2 << " " << i.x3 << "\n";
    // }

    v.push_back({1,2,3});
    cout << v[0].x1;
   return 0;
}