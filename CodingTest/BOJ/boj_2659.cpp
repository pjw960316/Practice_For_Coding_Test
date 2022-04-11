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

vector<int> v3;
set<int> s;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	for (int a = 1; a < 10; a++)
	{
		for (int b = 1; b < 10; b++)
		{
			for (int c = 1; c < 10; c++)
			{
				for (int d = 1; d < 10; d++)
				{
					if (a <= b && b <= c && c <= d)
					{
						v3.push_back(a * 1000 + b * 100 + c * 10 + d);
					}
					int tmp1 = 1000 * a + 100 * b + 10 * c + d;
					int tmp2 = 1000 * b + 100 * c + 10 * d + a;
					int tmp3 = 1000 * c + 100 * d + 10 * a + b;
					int tmp4 = 1000 * d + 100 * a + 10 * b + c;
					int tmp = min(min(tmp1, tmp2), min(tmp3, tmp4));
					s.insert(tmp);
				}
			}
		}
	}

	/*for (auto i : v3)
	{
		cout << i << "  ";
	}
	cout << "\n\n";


	for (auto i : s)
	{
		cout << i << "  ";
	}
	cout << "\n\n";*/

	vector<int> v2;
	int a;
	for (int i = 0; i < 4; i++)
	{
		cin >> a;
		v2.push_back(a);
	}
	int tmp1 = 1000 * v2[0] + 100 * v2[1] + 10 * v2[2] + v2[3];
	int tmp2 = 1000 * v2[1] + 100 * v2[2] + 10 * v2[3] + v2[0];
	int tmp3 = 1000 * v2[2] + 100 * v2[3] + 10 * v2[0] + v2[1];
	int tmp4 = 1000 * v2[3] + 100 * v2[0] + 10 * v2[1] + v2[2];

	int tmp = min(min(tmp1, tmp2), min(tmp3, tmp4));
	int cnt = 1;
	for (auto i : s)
	{
		if (i == tmp)
		{
			cout << cnt;
			return 0;
		}
		cnt++;
	}
	return 0;
}


