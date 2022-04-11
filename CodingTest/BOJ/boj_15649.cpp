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

//DFS를 완벽하게 구현해봅시다.

int n, m;
int arr[9];
bool is_out = false;
void Dfs(int depth)
{
	if (depth >= m)
	{
		for (int i = 0; i < m; i++)
		{
			cout << arr[i] << " ";
		}
		cout << "\n";
		return;
	}
	for (int i = 1; i <= n; i++)
	{
		is_out = false;	
		for (int k = 0; k < depth; k++)
		{
			if (arr[k] == i)
			{
				is_out = true;
				break;
			}
		}
		if (is_out == false)
		{
			arr[depth] = i;	
			Dfs(depth + 1);
		}		
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	Dfs(0);
	return 0;
}


