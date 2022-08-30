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

struct str
{
    int r;
    int c;
    int day;
};

queue<str> q;
int arr[1001][1001];
pair<int,int> path[4] = {{-1,0} , {1,0} , {0,-1} , {0,1}};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int m,n;
    int cur_day = 1;
    int cur_good_tomato_cnt = 0;
    int minus_one_cnt = 0;
    cin >> m >> n;

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            cin >> arr[i][j];
            if(arr[i][j] == 1) //이미 익은 토마토 색출
            {
                q.push({i,j,1});
                cur_good_tomato_cnt++;
            }
            if(arr[i][j] == -1)
            {
                minus_one_cnt++;
            }
        }
    }

    int all_tomato = n*m - minus_one_cnt;

    if(cur_good_tomato_cnt == all_tomato)
    {
        cout << 0;
        return 0;
    }

    cur_day = q.front().day;
    int cur_r = 0,cur_c = 0;
    while(q.empty() == false)
    {
        for(int i=0; i<4; i++)
        {
            cur_r = q.front().r + path[i].first;
            cur_c = q.front().c + path[i].second;
           
            if(cur_r == 0 || cur_r == n+1 || cur_c == 0 || cur_c == m+1)
            {
                continue;
            }
            //이제 익으니까 익은 토마토 증가 후 큐에 넣기
            if(arr[cur_r][cur_c] == 0) 
            {
                cur_good_tomato_cnt++;
                if(cur_good_tomato_cnt == all_tomato) //모든 토마토가 익으면 끝내기
                {
                    cout << q.front().day;

                    //test

                    // cout << "\n";
                    // for(int i=1; i<=n; i++)
                    // {
                    //     for(int j=1; j<=m; j++)
                    //     {
                    //         cout << arr[i][j] << " ";
                    //     }
                    //     cout << "\n";
                    // }
                    return 0;
                }
                arr[cur_r][cur_c] = 1;
                q.push({cur_r,cur_c,q.front().day+1});                
            }
        }
        q.pop();
    }

    
    cout << -1;

   return 0;
}