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

vector<pair<int, int>> v;
queue<int> q;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m,num1,num2;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> num1 >> num2;
        v.push_back({ num1,num2 });
    }

    int count = 0;
    bool is_find = false;
    for (int i = 2; i <= n; i++)
    {
        is_find = false;
        count = 0;
        q.push(i);      

        while (1)
        {           
            for (auto j : v)
            {
                if (j.second == q.front())
                {
                    cout << i << " " << j.first << " " << j.second << "\n";
                    if (q.front() == 1)
                    {            
                        is_find = true;
                        break;
                    }
                    q.push(j.first);
                }
            }
            if (is_find == true)
            {
                while (q.empty() == false)
                {
                    q.pop();
                }
                break;
            }
            else
            {
                q.pop();
            }
            count++;
        }
        cout << i << " : " << count << "\n";
    }
    return 0;
}