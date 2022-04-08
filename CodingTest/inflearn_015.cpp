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

int arr[200001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    int mmax = 200000;
    //using inflearn_014 algorithm
    arr[0] = -1;
    arr[1] = -1;
    for (int i = 2; i <= mmax/2; i++)
    {
        if (arr[i] != 0)
        {
            continue;
        }
        for (int j = 2; j <= 1231123; j++)
        {
            if (i * j > mmax)
            {
                break;
            }
            arr[i * j] = -1;
        }
    }
    
    int cnt = 0;
    for (int i = 2; i <= n; i++)
    {
        if (arr[i] == 0)
        {
            cnt++;
        }
    }
    cout << cnt;

    return 0;
}