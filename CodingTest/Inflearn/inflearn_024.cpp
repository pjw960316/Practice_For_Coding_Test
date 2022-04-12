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

int arr[101];
vector<int> v;
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

    for (int i = 0; i < n - 1; i++)
    {
        v.push_back(abs(arr[i] - arr[i + 1]));
    }
    sort(v.begin(), v.end());

    int criteria = 1;
    for (auto i : v)
    {
        if (i != criteria)
        {
            cout << "NO";
            return 0;
        }
        criteria++;
    }

    cout << "YES";
    return 0;
}