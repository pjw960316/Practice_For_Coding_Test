#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <string>
#include <algorithm>
#include <utility>
#include <cmath>
#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;
using ll = long long;

//https://gglifer-cs.tistory.com/24
//를 기반으로 KnapSack을 공부했다.

int L[22];
int J[22];
int dp[22][101];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
   

    // Set up : Input
    int N; cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> L[i];
    for (int i = 1; i <= N; i++)
        cin >> J[i];

    // Process
    /* dp[i][j] = 체력 j 에서 1~i 번째의 각 사람들에게 인사를 하거나 하지 않았을 경우 얻을 수 있는 최대 기쁨 */
    memset(dp, 0, sizeof(dp));

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= 100; j++) {
            dp[i][j] = dp[i - 1][j]; /* i 번째 사람에게 인사를 할 수 없다면 */
            if (j - L[i] > 0) { /* i 번째 사람에게 인사를 할 수 있다면 */
                dp[i][j] = max(dp[i][j], dp[i - 1][j - L[i]] + J[i]);
            }
        }
    }

    /*for (int i = 1; i <= 3; i++)
    {
        for (int j = 1; j <= 100; j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << "\n\n";
    }*/

    cout << dp[N][100] << endl;
	return 0;
}


