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

int arr[1001][1001];
int dp[1001][1001];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int r,c;
    cin >> r >> c;
    for(int i=1; i<=r; i++)
    {
        for(int j=1; j<=c; j++)
        {
            cin >> arr[i][j];
            dp[i][j] = arr[i][j];
        }
    }

    for(int i=1; i<=r; i++)
    {
        for(int j=1; j<=c; j++)
        {
            dp[i][j] = max(dp[i][j] , dp[i-1][j-1] + arr[i][j]);
            dp[i][j] = max(dp[i][j] , dp[i-1][j] + arr[i][j]);
            dp[i][j] = max(dp[i][j] , dp[i][j-1] + arr[i][j]);
        }
    }

    cout << dp[r][c];
    
   return 0;
}