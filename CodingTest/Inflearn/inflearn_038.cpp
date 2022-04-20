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

int input[101];
int arr[101];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> input[i];
    }
    for (int i = 0; i < n; i++)
    {
        arr[i] = 10000;
    }

    int idx = -1;
    int cur = -1;
    for (int i = 0; i < n; i++)
    {
        cur = input[i];
        idx = input[i] + i;
        int small_cnt = 0;
        for (int j = 0; j <= idx; j++)
        {
            if (arr[j] < cur)
            {
                small_cnt++;
            }
        }       
        idx = idx - i + small_cnt;
        arr[idx] = cur;
    }
    return 0;
}