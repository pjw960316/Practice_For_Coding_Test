#include <string>
#include <vector>

using namespace std;

int solution(vector<int> v) 
{
    int answer = 0;
    
    for(int i=1; i<=v.size(); i++)
    {
        int sum = 0;
        for(auto j : v)
        {
            if(i <= j)
            {
                sum++;
            }
        }
        if(i <= sum)
        {
            answer = i;
        }
        else
        {
            return answer;
        }
    }
    return answer;
}