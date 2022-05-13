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

int n, m;
int arr[22][22];
int ans = 0;
int visit[22];
void Dfs(int node , int depth)
{
    if (node == n && depth < n)
    {
        ans++;
        return;
    }
    if (depth >= n)
    {
        return;
    }

    bool is_ignore = false;
    for (int i = 1; i <= n; i++)
    {
        is_ignore = false;
        //2가지 조건
        //1. 연결 X라면 무시
        if (arr[node][i] == 0)
        {
            continue;
        }
        //2. 방문했었으면 무시
        for (int j = 0; j <= depth; j++)
        {
            if (visit[j] == i)
            {
                is_ignore = true;
                break;
            }
        }
        if (is_ignore == true)
        {
            continue;
        }

        visit[depth + 1] = i;
        Dfs(i, depth + 1);
    }
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n1, n2;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> n1 >> n2;
        arr[n1][n2] = 1;
    }

    visit[0] = 1;
    Dfs(1,0);
    
    cout << ans;
    return 0;
}