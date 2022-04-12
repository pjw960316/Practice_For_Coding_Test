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
map<int, int> m;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    int num;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        arr[i] = num;
        v.push_back(num);
    }    
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());

    for (unsigned int i = 0; i < v.size(); i++)
    {
        int idx = (int)i + 1;
        m.insert({ v[i], idx });
    }

    for (int i = 0; i < n; i++)
    {
        cout << m[arr[i]] << " ";
    }
    return 0;
}