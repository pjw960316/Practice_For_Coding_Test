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

int mmax = -1;
int ans = -1;
void digit_sum(int x)
{
    string str = to_string(x);
    int sum = 0;
    for (auto i : str)
    {
        sum += i - '0';
    }
    if (mmax < sum)
    {
        mmax = sum;
        ans = x;
    }
    if (mmax == sum)
    {
        if (ans < x)
        {
            ans = x;
        }
    }
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n,num;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        digit_sum(num);
    }
    cout << ans;
    return 0;
}