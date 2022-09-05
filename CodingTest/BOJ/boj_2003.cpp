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

ll arr[100000];
ll sum[100000];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int p1=1, p2=1;

    ll n,m;
    cin >> n >> m;
    for(int i=1; i<=n; i++)
    {
        cin >> arr[i];
    }

    sum[0] = 0;
    for(int i=1; i<=n; i++)
    {
        sum[i] = sum[i-1] + arr[i];
    }

    int ans = 0;
    while(1)
    {        
        ll tmp = sum[p2] - sum[p1-1];
        if(tmp == m)
        {
            ans++;
            p1++;
            p2 = p1;
            if(p1 == n)
            {
                cout << ans;
                return 0;
            }
        }
        else if(tmp < m)
        {
            p2++;
            if(p2 == n+1)
            {
                if(p1 == n)
                {
                    cout << ans;
                    return 0;
                }
                p1++;
                p2 = p1;
            }
        }
        else
        {
            p1++;
            p2 = p1;
            if(p1 == n+1)
            {
                cout << ans;
                return 0;
            }
        }
    }

   return 0;
}