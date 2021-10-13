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
			if (arr[j] > arr[i] && dp[j] >= dp[i]) //���� idx�� ��ȸ�Ѵ�.
			{
				dp[i] = dp[j]+1;
				is_big = false;
			}
			if (is_big == true && j == i-1) //��ȸ�� ���������� �ұ��ϰ� ���� ���� ū ���.
			{
				dp[i] = 1;
			}
			//bool�� ������� �ʰ� , �� ����� �ڵ尡 ������ �б����� ���� �� , ���� �� ����� �� �����ϱ� ����.
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


