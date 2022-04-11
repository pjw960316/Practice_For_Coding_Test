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

using ll = long long;
using namespace std;

pair<int, int> path[4] = { {0,-1},{-1,0},{0,1},{1,0} };
char arr[252][252];
int visit[252][252];
queue<pair<int, int>> q;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int r, c;
	cin >> r >> c;

	memset(arr, '#', sizeof(arr));
	for (int i = 1; i <= r; i++)
	{
		for (int j = 1; j <= c; j++)
		{
			cin >> arr[i][j];
		}
	}
		
	int all_lamb = 0, all_wolf = 0;
	int lamb = 0, wolf = 0;
	int cur_r, cur_c;
	for (int i = 1; i <= r; i++)
	{
		for (int j = 1; j <= c; j++)
		{
			lamb = 0;
			wolf = 0;
			if (arr[i][j] != '#' && visit[i][j] == 0)
			{
				visit[i][j] = 1; //언제나 visit을 바로바로 적어서 무한루프를 방지한다.
				q.push({ i,j });

				if (arr[i][j] == 'o')
				{
					lamb++;
				}
				if (arr[i][j] == 'v')
				{
					wolf++;
				}	
			
				while (q.empty() == false)
				{		
					for (int k = 0; k < 4; k++)
					{
						cur_r = q.front().first + path[k].first;
						cur_c = q.front().second + path[k].second;
						if (visit[cur_r][cur_c] == 0)
						{
							visit[cur_r][cur_c] = 1; //언제나 visit을 바로바로 적어서 무한루프를 방지한다.
							if (arr[cur_r][cur_c] == '#')
							{
								continue;
							}							
							q.push({ cur_r,cur_c });
							if (arr[cur_r][cur_c] == 'o')
							{
								lamb++;								
							}
							if (arr[cur_r][cur_c] == 'v')
							{
								wolf++;
							}
						}										
					}					
					q.pop();
				}
				if (lamb <= wolf)
				{
					all_wolf += wolf;
				}
				else
				{
					all_lamb += lamb;
				}
			}
		}
	}

	cout << all_lamb << " " << all_wolf;

	return 0;
}