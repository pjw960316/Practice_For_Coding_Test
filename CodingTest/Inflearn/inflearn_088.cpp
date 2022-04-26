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

int arr[9][9];
int ans[9][9];
bool visit[9][9];


void Bfs(int r, int c)
{
    queue<pair<int, int>> q;
    q.push({ r, c });
    visit[r][c] = true;
    while (q.empty() == false)
    {        
        for (int i = 0; i < 4; i++)
        {
            int cur_r = q.front().first + path[i].first;
            int cur_c = q.front().second + path[i].second;
            if (arr[cur_r][cur_c] == 0 && visit[cur_r][cur_c] == false)
            {
                ans[cur_r][cur_c] = ans[q.front().first][q.front().second] + 1;
                visit[cur_r][cur_c] = true;
                q.push({ cur_r, cur_c });
            }
        }
        q.pop();
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            arr[i][j] = 1;
        }
    }
    for (int i = 1; i <= 7; i++)
    {
        for (int j = 1; j <= 7; j++)
        {
            cin >> arr[i][j];
        }
    }
    for (int i = 1; i <= 7; i++)
    {
        for (int j = 1; j <= 7; j++)
        {
            if (visit[i][j] == false && arr[i][j] == 0)
            {
                Bfs(i, j);
            }
        }
    }

   /* for (int i = 1; i <= 7; i++)
    {
        for (int j = 1; j <= 7; j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << "\n";
    }*/
    cout << ans[7][7];

    return 0;
}