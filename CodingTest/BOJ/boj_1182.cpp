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

int arr[21];
int n, s, num;
int cnt = 0;

void Dfs(int depth , int sum)
{	
	sum += arr[depth];
	if (depth >= n)
	{
		return;
	}
	if (sum == s)
	{
		cnt++;
	}	
	Dfs(depth + 1, sum - arr[depth]);
	Dfs(depth + 1, sum);	
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
		
	cin >> n >> s;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}		
	Dfs(0,0);
	cout << cnt;
	return 0;
}


