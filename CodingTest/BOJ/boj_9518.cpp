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

int arr[52][52];
int mmax;
int result = 0;
pair<int, int> max_loc;

pair<int, int> path[8] = { {-1,-1} , {-1,0} , {-1,1} , {0,-1} , {0,1} , {1,-1} , {1,0} , {1,1} };
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int r, c;
	char person;
	cin >> r >> c;
	memset(arr, '.', sizeof(arr));

	for (int i = 1; i <= r; i++)
	{
		for (int j = 1; j <= c; j++)
		{
			cin >> person;
			arr[i][j] = person;
		}
	}

	max_loc = { -1,-1 };
	int tmp;
	for (int i = 1; i <= r; i++)
	{
		for (int j = 1; j <= c; j++)
		{
			tmp = 0;
			if (arr[i][j] == '.')
			{
				for (int k = 0; k < 8; k++)
				{
					if (arr[i + path[k].first][j + path[k].second] == 'o')
					{
						tmp += 1;
					}
				}
				if (max(tmp, mmax) == tmp)
				{
					mmax = max(tmp, mmax);
					max_loc = { i,j };
				}				
			}
		}
	}
	if (max_loc.first != -1)
	{
		arr[max_loc.first][max_loc.second] = 'o';
	}
	
	for (int i = 1; i <= r; i++)
	{
		for (int j = 1; j <= c; j++)
		{
			if (arr[i][j] == 'o')
			{
				for (int k = 0; k < 8; k++)
				{
					if (arr[i + path[k].first][j + path[k].second] == 'o')
					{
						result++;
					}
				}
			}
		}
	}

	cout << result / 2;
	return 0;
}


