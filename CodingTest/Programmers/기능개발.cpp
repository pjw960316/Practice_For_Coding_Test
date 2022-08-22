#include <string>
#include <vector>
#include <deque>
#include <iostream>

using namespace std;

deque<int> p,s;
vector<int> solution(vector<int> progresses, vector<int> speeds)
{
    vector<int> answer;
    for(auto i : progresses)
    {
        p.push_back(i);
    }
    for(auto i : speeds)
    {
        s.push_back(i);
    }
    
    while(true)
    {
        if(p.empty() == true)
        {
            return answer;
        }
        
        //1. 계산
        for(int i=0; i<p.size(); i++)
        {
            p[i] += s[i];
        }
        
        //2. 제거
        // 제거하면 사이즈가 달라지므로 검사만
        int erase_count = 0;
        for(int i=0; i<p.size();i++)
        {
            if(p[i] >= 100)
            {
                erase_count++;
            }
            else
            {
                break;
            }
        }
        for(int i=0; i<erase_count; i++)
        {
            p.pop_front();
            s.pop_front();            
        }
        if(erase_count != 0)
        {
            answer.push_back(erase_count);
        }
    }
    
   
    return answer;
}