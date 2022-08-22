#include <string>
#include <vector>
#include <iostream>
#include <set>

using namespace std;
multiset<int> ms;
int solution(vector<int> scoville, int k) 
{
    int answer = 0;
    for(auto i : scoville)
    {
        ms.insert(i);
    }
    
    while(true)
    {
        int cnt = 0;
        int tmp = 0;
        for(auto i : ms)
        {
            if(cnt == 0)
            {
                tmp += i;
            }
            if(cnt == 1)
            {
                tmp += (i*2);
                break;
            }
            cnt++;
        }
        
        multiset<int>::iterator iter = ms.begin();
        ms.erase(iter);
        iter = ms.begin();
        ms.erase(iter);
        ms.insert(tmp);
        
        answer++;
        auto value = ms.begin();
         
        if(*(ms.begin()) >= k)
        {
            return answer;
        }
        
        if(ms.size() == 2)
        {
            int tmp = 0;
            vector<int> v;
            for(auto i : ms)
            {
                v.push_back(i);
            }
            if(v[0] + v[1] * 2 < k)
            {
                return -1;
            }
        }
    }
    
   
    return answer;
}