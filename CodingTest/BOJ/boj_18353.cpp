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

int arr[2002];
int dp[2002];
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
	bool is_big;
	for (int i = 2; i <= n; i++)
	{
		is_big = true;
		for (int j = 1; j < i; j++)
		{
			if (arr[j] > arr[i] && dp[j] >= dp[i]) //작은 idx를 순회한다.
			{
				dp[i] = dp[j]+1;
				is_big = false;
			}
			if (is_big == true && j == i-1) //순회를 마쳤음에도 불구하고 내가 가장 큰 경우.
			{
				dp[i] = 1;
			}
			//bool을 사용하지 않고 , 더 깔끔한 코드가 있지만 분기점을 나눌 때 , 나는 이 방식이 더 구현하기 쉽다.
		}		
	}

	int result = 0;
	for (int i = 1; i <= n; i++)
	{
		result = max(dp[i], result);
	}

	cout << n - result;
	return 0;
}


