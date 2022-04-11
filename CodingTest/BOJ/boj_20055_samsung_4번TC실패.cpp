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

deque<pair<bool, int>> d;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k,l;
	cin >> n >> k;
	for (int i = 0; i < 2*n; i++)
	{
		cin >> l;
		d.push_back({ false,l });
	}

	int down_idx = n - 1;
	int zero_cnt = 0;
	int level = 0;
	pair<bool,int> tmp;
	while (1)
	{
		level++;
		zero_cnt = 0;

		//1. deque �̵�		
		tmp = d.back();
		d.pop_back();
		d.push_front(tmp);

		if (d[down_idx].first == true)
		{
			d[down_idx].first = false;
		}
		//2. �κ� �̵�
		for (int i = 0; i < n - 1; i++) //������ ĭ�� �˻� X
		{
			if (d[i].first == true && d[i + 1].first == false && d[i + 1].second > 0)
			{
				d[i].first = false;
				d[i + 1].first = true;
				d[i + 1].second--;
				i += 1; //���� ĭ �˻� X
			}
		}
		if (d[down_idx].first == true)
		{
			d[down_idx].first = false;
		}

		//3. �κ� �ø���
		if (d[0].second > 0) 
		{
			d[0].first = true;
			d[0].second--;
		}

		//4. ������ �˻�
		for (auto i : d)
		{
			if (i.second == 0)
			{
				zero_cnt++;
			}
		}
		if (zero_cnt >= k)
		{
			cout << level; 
			return 0;
		}
	}
	return 0;
}


