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

    int arr[10];
    memset(arr, 0, sizeof(arr));

    for (auto i : str)
    {
        arr[i - '0'] += 1;
    }

    int mmax = -1;
    int ans = -1;
    int idx = 0;

    for (auto i : arr)
    {
        if (mmax <= i)
        {
            mmax = i;
            ans = idx;
        }
        idx++;
    }

    cout << ans;
    return 0;
}