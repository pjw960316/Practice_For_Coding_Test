#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <string>
#include <algorithm>
#include <utility>
#include <cmath>
#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

//왜 다시 ANSI로 하니까 잘 되는것인가

map<string, int> m;
vector<string> v;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout << "인코딩 테스트 문구";
    int cnt;
    cin >> cnt;
    string str;

    for (int i = 0; i < cnt; i++)
    {
        cin >> str;
        m.insert({ str,i + 1 });
    }

    for (int i = 0; i < cnt; i++)
    {
        cin >> str;     
        v.push_back(str);
    }

    int sum = 0;
    int max = cnt * (cnt - 1) / 2;
    for (int i = 0; i < cnt; i++)
    {
        for (int j = i + 1; j < cnt; j++)
        {
            if (m[v[i]] < m[v[j]])
            {
                sum++;
            }
        }
    }
    cout << sum << "/" << max;
    return 0;
}


