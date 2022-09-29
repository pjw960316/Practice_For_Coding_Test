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

map<int,vector<int>> m;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //map의 value를 vector로 할 때.
    vector<int> v; // 빈 벡터 형성

    m.insert({1,v});
    m.insert({2,v});
    
    m[1].push_back(2);
    m[1].push_back(3);
    m[1].push_back(4);

    m[2].push_back(12);
    m[2].push_back(13);
    m[2].push_back(14);
    
    for(auto i : m)
    {
        cout << i.second[0] << " " << i.second[1] << " " << i.second[2] << "\n";
    }
   return 0;
}