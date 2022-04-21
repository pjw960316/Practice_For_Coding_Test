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

    int arr[10][10];
    memset(arr, 0, sizeof(arr));

    int n1, n2;
    for (int i = 0; i < 6; i++)
    {
        cin >> n1 >> n2;
        arr[n1][n2] = 1;      
    }

    queue<int> q;
    q.push(1);
    while (q.empty() == false)
    {
        for (int i = 1; i <= 7; i++)
        {
            if (arr[q.front()][i] == 1)
            {
                q.push(i);
            }
        }

        cout << q.front() << " ";
        q.pop();
    }

    return 0;
}