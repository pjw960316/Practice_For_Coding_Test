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


int s, n, num;

int GetSize(vector<int> cache)
{
    int idx = 0;
    for (auto i : cache)
    {
        if (i == 0)
        {            
            return idx;
        }
        idx++;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> s >> n;

    vector<int> cache(s);
    vector<int> copied_cache(s);
    
    bool isHit = false;
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        isHit = false;
        int len = GetSize(cache);
        int idx = 0;

        for (auto i : cache)
        {
            if (i == num)
            {
                isHit = true;
                break;
            }
            idx++;
        }

        copied_cache = cache;
        if (isHit == true)
        {
            for (int j = 0; j < idx; j++)
            {
                cache[j + 1] = copied_cache[j];
            }              
        }
        else
        {
            if (len < s)
            {
                for (int j = 0; j < len; j++)
                {
                    cache[j + 1] = copied_cache[j];
                }               
            }
            else
            {
                for (int j = 0; j < len - 1; j++)
                {
                    cache[j + 1] = copied_cache[j];
                }
               
            }         
        }
        cache[0] = num;          
    }

    for (auto i : cache)
    {
        cout << i << " ";
    }
    return 0;
}