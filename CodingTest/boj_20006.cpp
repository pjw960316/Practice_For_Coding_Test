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
	int lv;
	int cnt;
	vector<pair<string, int>> person;
};
vector<str> v;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int player, limit ,lv;
	string name;
	bool is_getin = false;
	cin >> player >> limit;
	for (int i = 0; i < player; i++)
	{
		is_getin = false;	
		cin >> lv >> name;
		if (i == 0) 
		{			
			v.push_back({ lv,1 });
			v[0].person.push_back({ name , lv });		
			continue;
		}
		for (auto &j : v)
		{
			if (j.lv - 10 <= lv && lv <= j.lv + 10 && j.cnt < limit)
			{
				j.cnt += 1;		
				j.person.push_back({ name,lv });
				is_getin = true;
				break;
			}
		}
		if (is_getin == false)
		{
			v.push_back({ lv,1 });
			v[v.size()-1].person.push_back({ name , lv });
		}		
	}

	for (auto &i : v)
	{
		sort(i.person.begin(), i.person.end());
	}
	for (auto i : v)
	{		
		if (i.cnt == limit)
		{
			cout << "Started!\n";
			for(auto j : i.person)
			{
				cout << j.second << " " << j.first << "\n";
			}
		}
		else
		{
			cout << "Waiting!\n";
			for (auto j : i.person)
			{
				cout << j.second << " " << j.first << "\n";
			}
		}
	}
	return 0;
}


