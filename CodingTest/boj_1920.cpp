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

vector<int> v1, v2;

int BinarySearch(int start , int end , int n)
{
	int mid = (start + end) / 2;
	if (start > end)
	{
		return -1;
	}	
	if (n < v1[mid])
	{
		return BinarySearch(start, mid-1, n);
	}
	else if (n > v1[mid])
	{
		return BinarySearch(mid+1, end, n);
	}
	else
	{
		return 1;
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n,m,num;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		v1.push_back(num);
	}
	sort(v1.begin(), v1.end());
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> num;
		v2.push_back(num);
	}

	for (int i=0; i<m; i++)
	{
		if (BinarySearch(0,n-1,v2[i]) == -1)
		{
			cout << "0\n";
		}
		else
		{
			cout << "1\n";
		}
	}
	return 0;
}