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

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int tc;
	string tmp;
	string ans;
	string str;
	queue<string> q;
	bool can_out = false;
	int path[4] = { -3,-1,1,3 };
	cin >> tc;

	for (int i = 0; i < tc; i++)
	{
		int clicked_cnt = 0;
		ans.clear();	
		can_out = false;

		for (int j = 0; j < 3; j++)
		{
			cin >> tmp;
			for (int k = 0; k < 3; k++)
			{
				ans.push_back(tmp[k]);
			}
		}		
		string str = ".........";
		q.push(str);
		int cur;
		string copy_str;		
		
		while (q.empty() == false)
		{
			for (int i = 0; i < 9; i++)
			{
				copy_str = q.front();
				
				if (q.front()[i] == '*')
				{
					copy_str[i] = '.';
				}
				else
				{
					copy_str[i] = '*';
				}
				for (int j = 0; j < 4; j++)
				{
					//좌표로 했어야 했다
					cur = i + path[j];
					if (i == 2 && cur == 3)
					{
						continue;
					}
					if (i == 3 && cur == 2)
					{
						continue;
					}
					if (i == 5 && cur == 6)
					{
						continue;
					}
					if (i == 6 && cur == 5)
					{
						continue;
					}					
					if (0 <= cur && cur < 9)
					{
						if (q.front()[cur] == '*')
						{
							copy_str[cur] = '.';
						}
						else
						{
							copy_str[cur] = '*';
						}
					}			
				}
				clicked_cnt++;
				//cout << copy_str << "    " << ans << "\n";
				if (copy_str == ans)
				{
					can_out = true;
					break;
				}				
				q.push(copy_str);
			}
			
			if (can_out == true)
			{
				int ret = 1;
				//cout << "cc : " << clicked_cnt << " ";
				while (clicked_cnt > 9)
				{
					clicked_cnt = clicked_cnt / 9;
					ret++;
				}
				cout << ret << "\n";
				break;
			}
			q.pop();
		}
	}
	return 0;
}


