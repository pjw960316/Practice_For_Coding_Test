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

map<string,pair<int,int>> m;

string convertTime(string ttime)
{
    string str = "";
    for(auto i : ttime)
    {
        if(i != ':')
        {
            str.push_back(i);
        }
    }
    return str;
}
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s = "";
    string e = "";
    string q = "";
    cin >> s >> e >> q;
    string start_time = convertTime(s);
    string end_time = convertTime(e);
    string end_time2 = convertTime(q);

    while(1)
    {
        string ttime = "";
        string name = "";
        cin >> ttime >> name;  

        if(ttime == "" && name == "")
        {
            break;
        }

        string new_time = convertTime(ttime);
        
        //initialize map
        if(m.find(name) == m.end())
        {
            m.insert({name , {0,0}});
        }

        if(new_time <= start_time)
        {
            m[name].first = 1;         
        }

        if(end_time <= new_time && new_time <= end_time2)
        {
            m[name].second = 1;
        }
    }

    int ans = 0;
    for(auto i : m)
    {
        if(i.second.first + i.second.second == 2) //both 1
        {
            ans++;
        }
    }
    cout << ans;
	return 0;
}