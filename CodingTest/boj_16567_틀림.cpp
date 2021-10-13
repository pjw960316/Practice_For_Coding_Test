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

int road[1000001];
map<int, int> dirty;

void Change(int i)
{
	road[i] = 1;
	int first_road = i;
	if (road[i - 1] == 0 && road[i + 1] == 0)
	{
		dirty.insert({ i,i });
		return;
	}
	if (road[i - 1] == 1 && road[i + 1] == 0)
	{
		for (auto j : dirty)
		{
			if (j.second == i - 1)
			{
				dirty[j.first] = i;
				return;
			}
		}		
	}
	if (road[i - 1] == 0 && road[i + 1] == 1)
	{
		int value = dirty[i + 1];
		dirty.erase(i+1);
		dirty.insert({ i,value });
		return;
	}
	if (road[i - 1] == 1 && road[i + 1] == 1)
	{
		for (auto j : dirty)
		{
			if (j.second == i - 1)
			{
				dirty[j.first] = dirty[i+1];				
			}
			dirty.erase(i + 1);
			return;
		}		
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	string str;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> road[i];
	}

	int k, v;
	for (int i = 0; i < n; i++)
	{
		if (road[i] == 1)
		{
			k = i;
			while (road[i] == 1)
			{
				i++;
			}
			v = i-1;
			dirty.insert({ k,v });
		}		
	}

	getchar();
	int dirty_idx;
	for (int i = 0; i < m; i++)
	{
		getline(cin, str);
		if (str == "0")
		{
			cout << dirty.size() << "\n";
		}
		else
		{		
			dirty_idx = str[str.size() - 1] - '0';		
			if (road[dirty_idx-1] == 0)
			{
				Change(dirty_idx-1);
			}
		}
	}
	return 0;
}


