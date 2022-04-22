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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    queue<int> q;
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        q.push(i + 1);
    }

    int cnt = 0;
    while (q.empty() == false)
    {
        if (q.size() == 1)
        {
            cout << q.front();
            return 0 ;
        }
       
        cnt++;
        if (cnt != m)
        {
            q.push(q.front());
        }    
        else
        {
            cnt = 0;
        }
        q.pop();
    }
    return 0;
}