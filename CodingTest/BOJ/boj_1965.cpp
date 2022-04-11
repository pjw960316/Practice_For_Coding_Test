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

int arr[1001];
int dp[1001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}
	
	dp[1] = 1;
	bool is_too_small;
	for (int i = 2; i <= n; i++)
	{
		is_too_small = true;
		for (int j = 1; j < i; j++)
		{
			if (arr[j] < arr[i] && dp[j]+1 > dp[i])
			{
				dp[i] = dp[j] + 1;
				is_too_small = false;
			}		
			if (j == i - 1 && is_too_small == true)
			{
				dp[i] = 1;
			}
		}		
	}
	/*
	for (int i = 1; i <= n; i++)
	{
		cout << dp[i] << " ";
	}
	cout << "\n\n";*/
	
	int result = 0;
	for (auto i : dp)
	{
		result = max(result, i);
	}
	cout << result;
	return 0;
}