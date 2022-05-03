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
    int c;
};

bool Cmp(str i, str j)
{
    if (i.a == j.a)
    {
        if (i.b < j.b)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    return true;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    priority_queue<int> pq;
    priority_queue<int, vector<int>, greater<int>> pq2;
    priority_queue<int, vector<int>, less<int>> pq3;

    //priority_queue<int, vector<int>, Cmp) pq4;

    map<int, int> m;
    m.insert({ 2, 1 });
    m[1] = 1;
    cout << m[1] << m[2] << "\n";

    str obj;
    obj = { 1,2,3 };

    deque<str> d;
    d.push_back(obj);
    obj = { 1,3,4 };
    d.push_back(obj);
    obj = { 1,1,4 };
    d.push_back(obj);

    sort(d.begin(), d.end(), Cmp);
    
    d.pop_front();
    for (auto &i : d)
    {
        cout << i.a << " " << i.b << " " << i.c << "\n";
    }
    

    return 0;
}