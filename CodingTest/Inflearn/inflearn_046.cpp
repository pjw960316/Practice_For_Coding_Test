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


int arr[2001];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,num;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {        
        cin >> arr[i];
    }

    int k;
    cin >> k;

    int idx = 1;
    int ttime = 0;
    while(1)
    {
        int sum = 0;
        for (int i = 1; i <= n; i++)
        {
            sum += arr[i];
        }
        if (sum == 0)
        {
            cout << -1;
            return 0;
        }

        if (ttime == k)
        {            
            while (1)
            {
                if (arr[idx] >= 1)
                {
                    cout << idx;
                    return 0;
                }
                else
                {
                    //move
                    if (idx == n)
                    {
                        idx = 1;
                    }
                    else
                    {
                        idx++;
                    }
                }
            }
            return 0;
        }
        if (arr[idx] >= 1)
        {
            arr[idx]--;
            ttime++;
        }

        //move
        if (idx == n)
        {
            idx = 1;
        }
        else
        {
            idx++;
        }
    }
   
    return 0;
}