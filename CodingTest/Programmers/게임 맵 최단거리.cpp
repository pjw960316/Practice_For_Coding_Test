#include <vector>
#include <queue>
#include <iostream>
using namespace std;

pair<int,int> path[4] = {{-1,0,} , {1,0} , {0,-1} , {0,1}};
int arr1[102][102]; //1,1 시작
int arr2[102][102];
int visit[102][102];

int solution(vector<vector<int>> maps)
{
    int n = maps.size();
    int m = maps[0].size();
    int answer = 0;
    //1. 맵 재생성
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            arr1[i+1][j+1] = maps[i][j];
        }
    }
    
    arr2[1][1] = 1;
    
    //2. 순회
    queue<pair<int,int>> q;
    q.push({1,1});
    int cur_r, cur_c;
    
    visit[1][1] = 1;
    while(q.empty() == false)
    {
        for(int i=0; i<4; i++)
        {
            cur_r = q.front().first + path[i].first;
            cur_c = q.front().second + path[i].second;
            //벽 X and 미방문
            if(arr1[cur_r][cur_c] == 1 && visit[cur_r][cur_c] == 0)
            {
                q.push({cur_r,cur_c});
                visit[cur_r][cur_c] = 1;
                arr2[cur_r][cur_c] = arr2[q.front().first][q.front().second] + 1;
            }
        }
        q.pop();
    }
    
    if(arr2[n][m] == 0)
    {
        answer = -1;
    }
    else
    {
        answer = arr2[n][m];
    }
    return answer;
}