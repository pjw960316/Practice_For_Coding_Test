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

//cout의 성질 학습

vector<double> v;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n,num;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		v.push_back(num);
	}
		
	sort(v.begin(), v.end());
	double sum = 0;
	for (auto i : v)
	{
		sum += i / 2;
	}
	sum += (double)v[v.size() - 1] / 2.0;

	cout << sum;
}


