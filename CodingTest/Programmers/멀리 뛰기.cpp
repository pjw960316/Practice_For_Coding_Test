#include <string>
#include <vector>
#include <iostream>

using namespace std;

long long dp[2001];
long long solution(int n) 
{
    long long answer = 0;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 3;
    dp[4] = 5;
    dp[5] = 8;
    for(int i=6; i<=n; i++)
    {
        dp[i] = dp[i-1] % 1234567 + dp[i-2] % 1234567;
    }
    answer = dp[n] % 1234567;
    return answer;
}