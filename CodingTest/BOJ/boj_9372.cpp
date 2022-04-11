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

vector<int> arr[1001];
int visited[1001];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int tc , world , plane ,n1, n2;
	int cnt;
	cin >> tc;
	for (int i = 0; i < tc; i++)
	{
		cnt = 0;
		cin >> world >> plane;
		for (int i = 0; i < plane; i++)
		{
			cin >> n1 >> n2;
		}
		/*for (int i = 0; i < world; i++)
		{
			arr[i].clear();
		}
		for (int i = 0; i < plane; i++)
		{
			cin >> n1 >> n2;
			arr[n1].push_back(n2);
			arr[n2].push_back(n1);
		}	
		for (int i = 0; i < world; i++)
		{
			visited[i] = 0;
		}		
		for (int i = 1; i < world; i++)
		{
			visited[i] = 1;
			for (auto j : arr[i])
			{
				if (visited[j] == 0)
				{
					cnt++;
					visited[j] = 1;
				}
			}
		}*/
		cout << world - 1 << "\n";
	}
	return 0;
}


