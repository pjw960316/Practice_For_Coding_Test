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

bool cmp(int a , int b)
{
	if (a > b)
	{
		return true;
	}
	else
	{
		return false;
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n,price;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> price;
		v.push_back(price);
	}
	sort(v.begin(), v.end() , cmp);

	int answer = 0;
	for (int i = 0; i < v.size(); i++)
	{
		if (i % 3 != 2)
		{
			answer += v[i];
		}
	}

	cout << answer;
	return 0;
}


