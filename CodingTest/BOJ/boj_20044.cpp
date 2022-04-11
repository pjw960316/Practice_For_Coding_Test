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

vector<int> v;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n,num;
	cin >> n;
	for (int i = 0; i < 2 * n; i++)
	{
		cin >> num;
		v.push_back(num);
	}
	sort(v.begin(), v.end());

	int sum = 2100000000;
	for (int i = 0; i < v.size()/2; i++)
	{		
		sum = min(sum, v[i] + v[v.size()-1 - i]);
	}


	cout << sum;
	return 0;
}