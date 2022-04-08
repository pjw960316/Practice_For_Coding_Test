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

    string str;
    getline(cin, str);
    string ans = "";
    
    for (auto i : str)
    {
        if ('a' <= i && i <= 'z')
        {
            ans.push_back(i);
        }
        if ('A' <= i && i <= 'Z')
        {
            ans.push_back(tolower(i));
        }
    }

    cout << ans;
    return 0;
}