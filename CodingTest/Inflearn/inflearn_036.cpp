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

vector<int> mminus;
vector<int> pplus;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,num;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        if (num > 0)
        {
            pplus.push_back(num);
        }
        else
        {
            mminus.push_back(num);
        }
    }
    for (auto i : mminus)
    {
        cout << i << " ";
    }
    for (auto i : pplus)
    {
        cout << i << " ";
    }
    return 0;
}