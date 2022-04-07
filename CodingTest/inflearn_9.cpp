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

int dp[1000000];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= 50000; i++)
    {
        for (int j = 1; j <= 50000; j++)
        {
            if (i * j <= 50000)
            {
                dp[i * j] += 1;
            }
            else
            {
                break;
            }
        }
    }
   
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cout << dp[i] << " ";
    }
    return 0;
}