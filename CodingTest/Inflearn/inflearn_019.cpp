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

int arr[102];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int ans = 0;
    bool is_big = false;
    for (int i = 0; i < n-1; i++)
    {
        is_big = false;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] <= arr[j])
            {
                is_big = true;
                break;
            }
        }
        if (is_big == false)
        {
            ans++;
        }
    }

    cout << ans;
    return 0;
}