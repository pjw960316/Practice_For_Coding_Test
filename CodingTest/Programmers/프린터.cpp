#include <string>
#include <vector>
#include <deque>
#include <iostream>

using namespace std;

int solution(vector<int> priorities, int location) 
{
    deque<pair<int,bool>> d;
    int idx = 0;
    for(auto i : priorities)
    {
        if(idx != location)
        {
            d.push_back({i,false});
        }
        else
        {
            d.push_back({i,true});
        }
        idx++;        
    }
    
    bool can_print = true;
    
    int answer = 0;
    while(1)
    {
        can_print = true;
        for(auto i : d)
        {
            if(i.first > d[0].first)
            {
                can_print = false;
                pair<int,bool> tmp = d[0];
                d.pop_front();
                d.push_back(tmp);
                break;
            }
        }
        
        if(can_print == true)
        {
            answer++;
            //무조건 가능
            if(d[0].second == true)
            {
                return answer;
            }
            else
            {
                d.pop_front();
            }
        }
    }
    
    return answer;
}