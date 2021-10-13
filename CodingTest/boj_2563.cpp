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
#include <unordered_set>
#include <unordered_map>

using ll = long long;
using namespace std;

int arr[101][101];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	memset(arr, 0, sizeof(arr));
	int cnt;
	cin >> cnt;
	int a, b;
	for (int i = 0; i < cnt; i++)
	{
		cin >> a >> b;
		for (int i = a; i < a + 10; i++)
		{
			for (int j = b; j < b + 10; j++)
			{
				arr[i][j] = 1;
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < 100; i++)
	{
		for (int j = 0; j < 100; j++)
		{
			if (arr[i][j] == 1)
			{
				ans++;
			}
		}
	}
	cout << ans;
	return 0;
}