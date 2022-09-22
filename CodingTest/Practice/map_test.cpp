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

    map<int, char> m1,m3;
    map<char, int> m2,m4;
    
    //1. map 초기화
    int idx = 0;
    for(auto i = 'a'; i<='z'; i++)
    {
        m1.insert({idx,i});
        m2.insert({i,idx});
        idx++;
    }
    
    idx = 0;
    for(auto i = 'A'; i<='Z'; i++)
    {
        m3.insert({idx,i});
        m4.insert({i,idx});
        idx++;
    }

    for(auto i : m1)
    {
        cout << i.first << " " <<i.second << "\n";
    }

   return 0;
}