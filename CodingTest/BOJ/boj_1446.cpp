#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <algorithm>
#include <utility>
#include <cmath>
#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <list>
#include <deque>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <queue>

using ll = long long;
using namespace std;

struct str
{
    int start;
    int end;
    int distance;
};

vector<str> v;
int dp[10001];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,d;
    cin >> n >> d;
    
    //초기값 설정
    for(int i=1; i<=d; i++)
    {
        dp[i] = i;
    }

    for(int i=0; i<n; i++)
    {
        int n1,n2,n3;
        cin >> n1 >> n2 >> n3;
        if(n2-n1 > n3 && n2 <= d)
        {
            v.push_back({n1,n2,n3});
        }
    }

    for(int idx=1; idx<=d; idx++)
    {
        dp[idx] = dp[idx-1]+1;
        for(auto i : v)
        {
            if(i.end == idx)
            {
                if(dp[i.start] + i.distance < dp[idx])
                {
                    dp[idx] = dp[i.start] + i.distance;
                }
            }
        }
    }
    cout << dp[d];

   return 0;
}