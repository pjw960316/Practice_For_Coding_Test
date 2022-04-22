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

int arr[21][21];
bool visit[21][21];
pair<int, int> path[8] = { {-1,0} , {0,-1} , {1,0} , {0,1} , {-1,-1} , {1,-1} , {-1,1} , {1,1} };

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }

    queue<pair<int, int>> q;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr[i][j] == 1 && visit[i][j] == 0)
            {
                ans++;
                q.push({ i,j });
                while (q.empty() == false)
                {
                    for (int k = 0; k < 8; k++)
                    {
                        int cur_r = q.front().first + path[k].first;
                        int cur_c = q.front().second + path[k].second;
                        if (arr[cur_r][cur_c] == 1 && visit[cur_r][cur_c] == 0 && cur_r>=0 && cur_c >=0 && cur_r <n && cur_c <n)
                        {
                            visit[cur_r][cur_c] = 1;
                            q.push({ cur_r, cur_c });
                        }
                    }
                    q.pop();
                }                
            }
        }
    }

    cout << ans;
    return 0;
}