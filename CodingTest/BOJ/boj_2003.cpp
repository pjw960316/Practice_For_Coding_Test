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

ll arr[100002];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int p1=0, p2=0;

    ll n,m;
    cin >> n >> m;
    for(int i=1; i<=n; i++)
    {
        cin >> arr[i];
    }

    int ans = 0;
    ll sum = 0;
    while(p1 <= p2)
    {          
        if(sum == m)
        {
            ans++;
            p1++;
            sum -= arr[p1];
        }
        else if(sum < m)
        {
            p2++;
            sum += arr[p2];
            if(p2 > n)
            {
                cout << ans;
                return 0;
            }
        }
        else
        {
            p1++;
            sum -= arr[p1];
        }
    }
    cout << ans;
    return 0;
}