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

pair<int, int> path[4] = { {-1,0} , {0,-1} , {1,0} , {0,1} };
int arr[51][51];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    memset(arr, 0, sizeof(arr));
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> arr[i][j];
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int cnt = 0;
            for (int k = 0; k < 4; k++)
            {
                if (arr[i][j] > arr[i + path[k].first][j + path[k].second])
                {
                    cnt++;
                }
            }
            if (cnt == 4)
            {
                ans++;
            }
            cnt = 0;          
        }
    }


    cout << ans;

    return 0;
}