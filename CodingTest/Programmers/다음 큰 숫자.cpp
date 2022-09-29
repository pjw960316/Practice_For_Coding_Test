#include <string>
#include <vector>
#include <iostream>

using namespace std;

int Solve(int n)
{
    int ans = 0;
    while(1)
    {
        if(n==1)
        {
            ans++;
            break;
        }
        else
        {
            if(n%2 == 1)
            {
                ans++;
            }
            n /= 2;
        }
    }
    return ans;
}
int solution(int n) 
{
    int answer = 0;
    
    int value = Solve(n);
    for(int i=n+1; i<=1000000; i++)
    {
        if(Solve(i) == value)
        {
            answer = i;
            return answer;
        }
    }
    return answer;
}