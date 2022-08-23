#include <string>
#include <vector>
#include <queue>

using namespace std;

queue<long long> q1;
queue<long long> q2;

// greedy
// 내가 더 작으면 취할 수 있는 행동은 큰 쪽에서 가져오는 방식밖에 없다.
int solution(vector<int> queue1, vector<int> queue2) 
{
    int answer = -2;
    
    int len = queue1.size();
    if(len == 0)
    {
        return -1;
    }
    
    long long q1_sum = 0 , q2_sum = 0;
    for(auto i : queue1)
    {
        q1_sum += i;
        q1.push(i);
    }
    for(auto i : queue2)
    {
        q2_sum += i;
        q2.push(i);
    }
    
    answer = 0;
    for(int i=0; i< len*3; i++)
    {
        if(q1_sum > q2_sum)
        {
            long long tmp = q1.front();
            q1.pop();
            q2.push(tmp);
            q1_sum -= tmp;
            q2_sum += tmp;
            answer++;            
        }
        else if(q1_sum < q2_sum)
        {
            long long tmp = q2.front();
            q2.pop();
            q1.push(tmp);
            q2_sum -= tmp;
            q1_sum += tmp;
            answer++;  
        }
        else
        {
            return answer;
        }
    }
    answer = -1;
    return answer;
}