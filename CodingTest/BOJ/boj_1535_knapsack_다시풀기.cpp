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

int dl[22];
int dj[22];

// 0-1 knapsack ����
// dp�� 1���� �迭�� �ƴ� 2���� �迭���� �����ϴ� ����
// 2�г� �� ��� ���縦 �����ϱ�

https://gglifer-cs.tistory.com/24
https://gsmesie692.tistory.com/113
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;	

	int minus[22];
	int plus[22];

	for (int i = 1; i <= n; i++)
	{
		cin >> minus[i];
	}
	for (int i = 1; i <= n; i++)
	{
		cin >> plus[i];
	}
	dl[0] = 100;
	dj[0] = 0;
	for (int i = 1; i <= n; i++)
	{
		if (plus[i] == 0) //�ູ���� 0�̸� �׳� ���� �� ġ��
		{
			dl[i] = -999;
		}
		else
		{		
			dl[i] = 100 - minus[i];
			dj[i] = plus[i];
			for (int j = 0; j < i; j++)
			{
				if (dl[j] - minus[i] > 0)
				{
					if (dj[j] + plus[i] > dj[i])
					{
						dl[i] = dl[j] - minus[i];
						dj[i] = dj[j] + plus[i];
					}
					else if (dj[j] + plus[i] < dj[i])
					{
						continue;
					}
					else
					{
						if (dl[j] - minus[i] > dl[i])
						{
							dl[i] = dl[j] - minus[i];
							dj[i] = dj[j] + plus[i];
						}
					}
				}
				else
				{
					continue;
				}				
			}
		}
	}

	/*for (int i = 0; i <= n; i++)
	{
		cout << dl[i] << " ";
	}

	cout << "\n";
	for (int i = 0; i <= n; i++)
	{
		cout << dj[i] << " ";
	}*/

	int ret = 0;
	for (auto i : dj)
	{
		ret = max(ret, i);
	}
	cout << ret;
	return 0;
}


