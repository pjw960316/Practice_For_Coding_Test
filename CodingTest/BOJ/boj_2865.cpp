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
using ll = long long;

bool Cmp(pair<double,int> a , pair<double,int> b)
{
	if (a.first > b.first)
	{
		return true;
	}
	else
	{
		return false;
	}
}

deque<pair<double, int>> v;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m, k;
	int win_cnt = 0;
	cin >> n >> m >> k;

	int num1;
	double num2;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> num1 >> num2;
			v.push_back({ num2,num1 });
		}
	}
	sort(v.begin(), v.end(), Cmp);
	set<int> s;
	double score = 0;
	
	while (win_cnt < k)
	{		
		if (s.empty() == true || s.find(v[0].second) == s.end())
		{
			score += v[0].first;
			s.insert(v[0].second);			
			win_cnt++;
		}
		v.pop_front();	
	}
	
	printf("%.1f", score);
	return 0;
}


