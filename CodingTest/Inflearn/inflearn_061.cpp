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

queue<pair<int,int>> q;
int arr[12];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int ans = 0;
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    q.push({ 0,0 });
    q.push({ arr[0] , 0 });
    if (arr[0] == m)
    {
        ans++;
    }
    q.push({ -arr[0] , 0 });
    if (-arr[0] == m)
    {
        ans++;
    }

    while (q.empty() == false)
    {
        int idx = q.front().second+1;
        if (idx < n)
        {
            q.push({ q.front().first, idx});
            q.push({ q.front().first + arr[idx] , idx});
            if (q.front().first + arr[idx] == m)
            {
                ans++;
            }
            q.push({ q.front().first - arr[idx] , idx});   
            if (q.front().first - arr[idx] == m)
            {
                ans++;
            }
        }        
        q.pop();           
    }

    if (ans == 0)
    {
        cout << -1;
        return 0;
    }

    cout << ans;
    return 0;
}