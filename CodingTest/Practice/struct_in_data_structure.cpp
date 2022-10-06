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

struct str
{
    int a;
    int b;
    string c;
};

set<str> s;
vector<str> v;

set<pair<int,int>> s_pair;
vector<pair<int,int>> v_pair;

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //1. struct test
    v.push_back({3,2,"bca"});
    v.push_back({2,25,"aaa"});
    v.push_back({4,1,"ewerwer"});

    //에러가 발생한다!
    //s.insert({3,2,"bca"});
    //s.insert({2,25,"aaa"});
    //s.insert({4,1,"ewerwer"});

    for(auto i : v)
    {
        cout << i.a << " " << i.b << " " << i.c << "\n";
    }
    /* 올바른 출력
    3 2 bca
    2 25 aaa
    4 1 ewerwer
    */

    //2. pair
    v_pair.push_back({3,2});
    v_pair.push_back({2,4});
    v_pair.push_back({4,-1});

    s_pair.insert({3,2});
    s_pair.insert({2,4});
    s_pair.insert({4,-1});

    for(auto i : v_pair)
    {
        cout << i.first << " " << i.second << "\n";
    }
    /* 올바른 출력
    3 2
    2 4
    4 -1
    */

    for(auto i : s_pair)
    {
        cout << i.first << " " << i.second << "\n";
    }
    /* 올바른 출력
    2 4
    3 2
    4 -1
    */
	return 0;
}