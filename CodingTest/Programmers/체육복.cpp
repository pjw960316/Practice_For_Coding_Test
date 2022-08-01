#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) 
{
    int answer = 0;
    
    sort(lost.begin() , lost.end());
    map<int,int> uniform;
    for(int i=1; i<=n; i++)
    {
        uniform.insert({i,1});
    }
    
    for(auto i : lost)
    {
        uniform[i]--;
    }
    
    for(auto i : reserve)
    {
        uniform[i]++;
    }
    
    for(auto i : lost)
    {
        if(uniform[i] >= 1)
        {
            continue;
        }
        else
        {
            if(uniform[i-1] == 2)
            {
                uniform[i-1]--;
                uniform[i]++;
                continue;
            }
            if(uniform[i+1] == 2)
            {
                uniform[i+1]--;
                uniform[i]++;
            }
        }
    }
    
    for(auto i : uniform)
    {
        if(i.second >= 1)
        {
            answer++;
        }
    }
    return answer;
}