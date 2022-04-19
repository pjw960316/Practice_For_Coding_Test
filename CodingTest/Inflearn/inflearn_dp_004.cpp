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

int dp[46];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 3;
    int n;
    cin >> n;

    for (int i = 4; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2]; //¾ÕÀÌ 1,2
    }

    cout << dp[n];
    return 0;
}