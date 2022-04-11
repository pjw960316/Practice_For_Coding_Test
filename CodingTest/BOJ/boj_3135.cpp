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

vector<int> v;

int click_cnt = 0;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int a, b;
	cin >> a >> b;
	
	int n, num;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		v.push_back(num);
	}

	int mmin = abs(a - b);
	int first = mmin;

	for (auto &i : v)
	{
		i = abs(i - b);
	}

	for (auto i : v)
	{
		mmin = min(mmin, i);
	}

	if (mmin != first)
	{
		click_cnt++;
	}
	click_cnt += mmin;

	cout << click_cnt;

	return 0;
}


