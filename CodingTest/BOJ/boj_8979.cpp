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

struct str
{
    int no;
    int g;
    int s;
    int b;
};
vector<str> v;

bool SortByMedal(str a , str b)
{
    if(a.g == b.g)
    {
        if(a.s == b.s)
        {
            return a.b > b.b;
        }
        return a.s > b.s;        
    }
    return a.g > b.g;    
}

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	
    int country_cnt , selected_country,answer,init_answer;
    int n,g,s,b;
    cin >> country_cnt >> selected_country;

    for(int i=1; i<=country_cnt; i++)
    {
        cin >> n >> g >> s >> b;
        v.push_back({n,g,s,b});
    }
    sort(v.begin() , v.end() , SortByMedal);
    int index = 0;    
    for(auto i : v)
    {
        if(i.no == selected_country)
        {
            init_answer = index;
            answer = init_answer;         
            break;
        }
        index++;
    }   
    for(int i=1; i<1001; i++)
    {
        if(v[init_answer].b == v[init_answer-i].b && v[init_answer].s == v[init_answer-i].s && v[init_answer].g == v[init_answer-i].g)
        {
            answer -= 1;
        }        
        else
        {
            cout << answer+1;
            return 0;
        }        
    }
	return 0;
}


