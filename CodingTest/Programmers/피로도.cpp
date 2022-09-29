#include <string>
#include <vector>
#include <iostream>

using namespace std;

int answer = -1;
int visit[8];
int max_dungeon = -1;
void Dfs(int pirodo , int depth , vector<vector<int>>& dungeons)
{
    if(depth == max_dungeon+1)
    {
        return;
    }
    for(int i=0; i<max_dungeon; i++)
    {
        bool is_visited = false;
        //이전에 해당 던전 지났는지
        for(int j=1; j<depth; j++)
        {
            if(visit[j] == i)
            {
                is_visited = true;
                break;
            }
        }
        // 피로도가 여유롭고 이전에 해당 던전을 방문하지 않았다면.
        if(pirodo >= dungeons[i][0] && is_visited == false)
        {
            //정답 갱신
            if(answer < depth)
            {
                answer = depth;
            }
            visit[depth] = i;
            Dfs(pirodo - dungeons[i][1] , depth+1 , dungeons);            
        }
    }
    return;
}

int solution(int k, vector<vector<int>> dungeons) 
{
    max_dungeon = dungeons.size();  
    Dfs(k , 1 , dungeons);  
    return answer;
}