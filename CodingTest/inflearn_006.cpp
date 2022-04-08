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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string str , str_num;
    bool flag = false;
    cin >> str;

    for (int i = 0; i < str.length(); i++)
    {
        if ('0' <= str[i] && str[i] <= '9')
        {
            if (str[i] == '0' && flag == true)
            {
                str_num.push_back(str[i]);
            }
            if(str[i] != '0')
            {
                flag = true;
                str_num.push_back(str[i]);
            }
        }
    }
    int ans = stoi(str_num);
    int cnt = 1;
    for (int i = 1; i <= ans / 2; i++)
    {
        if (ans % i == 0)
        {
            cnt++;
        }
    }
    cout << str_num << "\n";
    cout << cnt << "\n";
    return 0;
}