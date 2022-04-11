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
//�� ������� KnapSack�� �����ߴ�.

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
    /* dp[i][j] = ü�� j ���� 1~i ��°�� �� ����鿡�� �λ縦 �ϰų� ���� �ʾ��� ��� ���� �� �ִ� �ִ� ��� */
    memset(dp, 0, sizeof(dp));

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= 100; j++) {
            dp[i][j] = dp[i - 1][j]; /* i ��° ������� �λ縦 �� �� ���ٸ� */
            if (j - L[i] > 0) { /* i ��° ������� �λ縦 �� �� �ִٸ� */
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


