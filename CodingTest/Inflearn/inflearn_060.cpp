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

vector<int> v;
int global_sum = 0;
queue<int> q;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        global_sum += num;
        q.push(num);
        v.push_back(num);
    }

    int cal_cnt = 0;
    int tmp = 0;
    while (q.empty() == false)
    {
        if (cal_cnt > 10000) //10^4까지만 하면 최대치의 절반
        {
            cout << "NO";
            return 0;
            
        }
        for (int i = 0; i < n; i++)
        {
            cal_cnt++;
            tmp = q.front() + v[i];
            if (global_sum - tmp == tmp)
            {
                cout << "YES";
                return 0;
            }
            q.push(tmp);
        }
        q.pop();
    }
    cout << "NO";
    return 0;
}