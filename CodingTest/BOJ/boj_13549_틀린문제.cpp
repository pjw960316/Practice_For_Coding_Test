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

priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq; 
int visit[300009];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,k;
    cin >> n >> k;

    if(n==k)
    {
        cout << 0;
        return 0;
    }

    pq.push({0,n});
    visit[n] = 1;
    int answer_time = 999999999;

    while(pq.empty() == false)
    {
        int before_time = pq.top().first;
        int before_location = pq.top().second;

        visit[before_location] = 1;
        //cout << before_time << " " << before_location << "\n";
        //정답이면 하위 항목 진행 X
        if(before_location == k)
        {
            if(before_time < answer_time)
            {
                answer_time = before_time;
            }
            pq.pop();
            continue;
        }

        //1. 좌측
        if(visit[before_location-1] == 0 && before_location-1 >= 0)
        {
            pq.push({before_time+1 , before_location-1});      
        }

        //2. 우측
        if(visit[before_location+1] == 0 && before_location+1 <= k)
        {
            pq.push({before_time+1 , before_location+1}); 
        }

        //3. 텔레포트
        if(visit[before_location * 2] == 0 && before_location*2 <= k)
        {
            pq.push({before_time , before_location * 2});
        }

        pq.pop();
    }

    cout << answer_time;

   return 0;
}