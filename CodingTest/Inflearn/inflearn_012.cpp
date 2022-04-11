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

ll dp[15];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    dp[0] = 0;
    dp[1] = 0;
    dp[2] = 9 * 1;
    dp[3] = 90 * 2 + dp[2];
    dp[4] = 900 * 3 + dp[3];
    dp[5] = 9000 * 4 + dp[4];
    dp[6] = 90000 * 5 + dp[5];
    dp[7] = 900000 * 6 + dp[6];
    dp[8] = 9000000 * 7 + dp[7];
    dp[9] = 90000000 * 8 + dp[8];

    int n;
    cin >> n;
    string nn;
    nn = to_string(n);
    ll len = nn.length();
    ll small = pow(10, len - 1);
    cout << dp[len] + (n - small + 1) * len;
    return 0;
}