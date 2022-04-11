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

/*
"문제를 맞은 각 사람이 그 문제를 맞기 전까지 틀린 횟수의 총 합"
의 의미를 이해하지 못했습니다.
문제 이해 실패지 , 구현이 어려운 건 아니므로 넘어갑니다.
*/

using ll = long long;
using namespace std;

map<string, int> m;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n;
	int a, b, c, d, e;
	string id;
	int num;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a >> id >> num >> b >> c >> d >> e;
		if (id == "megalusion")
		{
			continue;
		}
		if (num == 4)
		{
			if (m.find(id) == m.end())
			{
				m.insert({ id,-1 });
				continue;
			}
			if (m[id] < 0) //맞은사람이 또 맞춤
			{
				continue;
			}
			else
			{
				m[id]++;
				m[id] = -m[id];
			}
		}
		else
		{
			if (m.find(id) == m.end())
			{
				m.insert({ id,1 });
				continue;
			}
			if (m[id] < 0) //맞은사람이 틀림
			{
				m[id]--;
			}
			else
			{
				m[id]++;
			}
			
		}
	}

	double correct_cnt = 0;
	double submit_cnt = 0;
	for (auto i : m)
	{
		if (i.second < 0)
		{
			correct_cnt++;
			submit_cnt -= (double)i.second;
		}
	}

	for (auto i : m)
	{
		if(i.second < 0)
			cout << i.first << " " << i.second << "\n";
	}
	cout << correct_cnt << " " << submit_cnt;

	return 0;

}