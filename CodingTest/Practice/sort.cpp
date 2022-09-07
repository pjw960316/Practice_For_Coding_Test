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

bool cmp(int a , int b)
{
    if(a < b)
    {
        return a < b;
    }
       
}

int main()
{
    v.push_back(1);
    v.push_back(5);
    v.push_back(5);
    v.push_back(3);
    v.push_back(7);

    sort(v.begin(), v.end() , cmp);
    for(auto i : v)
    {
        cout << i << " ";
    }
}