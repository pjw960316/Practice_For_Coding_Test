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

map<string,int> m;

bool cmp(pair<string,int> a , pair<string,int> b)
{
    //두 단어의 출현 횟수가 다르면 내림차순으로 정렬
    if(a.second != b.second)
    {
        return a.second > b.second;
    }
    //두 단어의 출현 횟수가 다르면 추가로 고려
    else
    {
        //두 단어의 길이가 다르면 길이에 따라 내림차순 정렬
        if(a.first.length() != b.first.length())
        {
            return a.first.length() > b.first.length();
        }
        else
        {
            return a.first < b.first;
        }
    }
}
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n1,n2;
    cin >> n1 >> n2;

    for(int i=0; i<n1; i++)
    {
        string str;
        cin >> str;
        //짧으면 패스
        if(str.length() < n2)
        {
            continue;
        }
        if(m.find(str) == m.end())
        {
            m.insert({str,1});
        }
        else
        {
            m[str]++;
        }
    }

    vector<pair<string,int>> v;
    for(auto i : m)
    {
        v.push_back({i.first, i.second});
    }

    sort(v.begin(), v.end(),cmp);

    for(auto i : v)
    {
        cout << i.first <<"\n";
    }
	return 0;
}