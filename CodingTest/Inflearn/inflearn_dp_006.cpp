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

int arr[101];
int dp[101];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    dp[0] = 1;

    int mmax = -1;
    for (int i = 1; i < n; i++)
    {
        mmax = -1;
        for (int j = 0; j < i; j++)
        {
            if (arr[j] < arr[i])
            {
                if (dp[j] + 1 > mmax)
                {
                    mmax = dp[j] + 1;
                }
            }
            else if (arr[j] > arr[i])
            {
                if (dp[j] > mmax)
                {

                }

            }
            else
            {       
                cout << "ERROR";
                return;
            }
        }
    }

    return 0;
}