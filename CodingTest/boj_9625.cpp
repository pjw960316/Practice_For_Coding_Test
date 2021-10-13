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

vector<pair<int, int>> v;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	v.push_back({ 1,0 });

	for (int i = 0; i < n; i++)
	{
		v.push_back({ v.back().second, v.back().second + v.back().first });
	}

	cout << v[v.size() - 1].first << " " << v[v.size() - 1].second;
	return 0;
}


