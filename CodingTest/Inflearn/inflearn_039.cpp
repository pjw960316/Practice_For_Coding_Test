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

int arr1[101];
int arr2[101];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n;
 
    for (int i = 0; i < n; i++)
    {
        cin >> arr1[i];
    }
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> arr2[i];
    }

    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        v.push_back(arr1[i]);
    }
    for (int i = 0; i < m; i++)
    {
        v.push_back(arr2[i]);
    }
    sort(v.begin(), v.end());
    for (auto i : v)
    {
        cout << i << " ";
    }
    return 0;
}