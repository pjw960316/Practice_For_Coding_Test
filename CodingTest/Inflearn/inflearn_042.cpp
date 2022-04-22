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

vector<int> v;
int m;
void Find(int s , int e)
{
    int mid = (s + e) / 2;
    if (v[mid] < m)
    {
        Find(mid+1 , e);
    }
    else if (v[mid] > m)
    {
        Find(s, mid-1);
    }
    else
    {
        cout << mid+1;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n >> m;

    int num;
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        v.push_back(num);
    }

    sort(v.begin(), v.end());

    int start = 0;
    int end = v.size() - 1;
    Find(start, end);

    return 0;
}