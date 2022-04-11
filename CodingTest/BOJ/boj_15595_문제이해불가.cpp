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
"������ ���� �� ����� �� ������ �±� ������ Ʋ�� Ƚ���� �� ��"
�� �ǹ̸� �������� ���߽��ϴ�.
���� ���� ������ , ������ ����� �� �ƴϹǷ� �Ѿ�ϴ�.
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
			if (m[id] < 0) //��������� �� ����
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
			if (m[id] < 0) //��������� Ʋ��
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