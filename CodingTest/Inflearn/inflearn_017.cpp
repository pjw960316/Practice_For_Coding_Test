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

    int n;
    int n1, n2;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> n1 >> n2;
        int sum = 0;
        for (int j = 1; j <= n1; j++)
        {
            sum += j;
        }
        if (n2 == sum)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }

    return 0;
}