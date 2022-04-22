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


int start, eend;
int ans = 0;

void Print(int s, int e)
{
    int sum = 0;
    for (int i = s; i < e; i++)
    {
        cout << i << " + ";
        sum += i;
    }
    sum += e;
    cout << e << " = " << sum <<"\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    int sum = 0; 
    for (int i = n/2; i >= 1; i--)
    {
        start = i;
        eend = i;    
        sum = i;
        while (1)
        {
            eend++;
            sum += eend;
            if (sum > n)
            {
                break;
            }
            if (sum == n)
            {
                Print(start, eend);
                ans++;
                break;
            }            
        }
    }

    cout << ans;
    return 0;
}