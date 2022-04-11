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
int visit[52][52];
queue<pair<int,int>> q;
pair<int, int> path[8] = { {-1,-1} , {-1,0} , {-1,1} , {0,-1} , {0,1} , {1,-1} , {1,0} , {1,1} };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int r, c;
	int island_num = 2;
	while(1)
	{
		memset(arr, 0, sizeof(arr));
		memset(visit, 0, sizeof(visit));
		island_num = 2;		

		cin >> c >> r;
		if (c == 0 && r == 0)
		{
			return 0;
		}
		for (int i = 1; i <= r; i++)
		{
			for (int j = 1; j <= c; j++)
			{
				cin >> arr[i][j];
			}
		}
		int cur_r, cur_c;
		for (int i = 1; i <= r; i++)
		{
			for (int j = 1; j <= c; j++)
			{
				if (arr[i][j] == 1 && visit[i][j] == 0)
				{
					//visit[i][j] = 1; //쓸모 없는 Visit 검사_1
					q.push({ i,j });					
					while (q.empty() == false)
					{
						arr[q.front().first][q.front().second] = island_num;	
						//visit[q.front().first][q.front().second] = 1; //쓸모 없는 Visit 검사_2
						for (int k = 0; k < 8; k++)
						{
							cur_r = q.front().first + path[k].first;
							cur_c = q.front().second + path[k].second;					
							if (arr[cur_r][cur_c] == 1 && visit[cur_r][cur_c] == 0)
							{											
								q.push({ cur_r, cur_c });
								visit[cur_r][cur_c] = 1;
							}
						}
						q.pop();
					}		
					island_num++;
				}
			}
		}

		cout << island_num - 2 << "\n";
	}
	return 0;
}


