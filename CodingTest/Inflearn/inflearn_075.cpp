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

map<int, vector<int>> m;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    int mm, d;
    int mmax = -1;
    int mmin = 1123123;


    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> mm >> d;
        if (mmax < d)
        {
            mmax = d;
        }
        if (mmin > d)
        {
            mmin = d;
        }
        m[d].push_back(mm);
    }

    vector<int> v;
    int sum = 0;
    for (int i = mmax; i >= mmin; i--)
    {
        for (auto j : m[i])
        {
            v.push_back(j);
        }
        if (v.empty() == true)
        {
            continue;
        }
        sort(v.begin(), v.end());
        //cout << v[v.size() - 1] <<"\n";
        sum += v[v.size() - 1];
        v.pop_back();
    }

    cout << sum;
  
    return 0;
}