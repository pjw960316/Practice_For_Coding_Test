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

//key = 값 , value = reminder
unordered_map<int,int> m;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a,b,c;
    cin >> a >> b >> c;

    int idx = 1;
    int modulo = idx;
    int org_a = a;
    for(int i=0; i<b; i++)
    {
        a = ((a%c) * (org_a%c)) % c;
        if(m.find(a) == m.end())
        {
            m.insert({a,idx});
        }
        else
        {
            modulo = idx-1;
            break;
        }
        idx++;
    }

    for(auto i : m)
    {
        if(i.second%modulo == b % modulo)
        {
            cout << i.first;
            return 0;
        }
    }
    return 0;
}