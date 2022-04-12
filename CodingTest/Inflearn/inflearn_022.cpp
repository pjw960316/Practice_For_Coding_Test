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

int dp[100001];
int arr[100001];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int mmax = -99999999;
    int sum = 0;
    for (int i = 0; i < k; i++)
    {
        sum += arr[i];
    }
    mmax = sum;

    int start = 0;
    int end = k-1;
    while (1)
    {
        end++;
        if (end >= n)
        {
            break;
        }
        sum = sum - arr[start] + arr[end]; //break로 예외처리를 했음
        if (mmax < sum)
        {
            mmax = sum;
        }
        start++;
    }

    cout << mmax;

    return 0;
}