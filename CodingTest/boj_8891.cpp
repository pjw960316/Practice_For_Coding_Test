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

struct str
{
	long long x;
	long long y;
	long long value;
};
vector<str> v1;
vector<str> v2;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	long long a = 1;
	long long b = 1;
	while (1)
	{
		if(b>=40000)
		{
			break;
		}
		v1.push_back({ 1,a,b });
		v2.push_back({ 1,a,b });
		b += a;
		a += 1;		
	}
	long long tmp_x = 0;
	long long tmp_y = 0;
	long long value = 0;
	
	for (auto i : v1)
	{
		tmp_x = 1;
		tmp_y = i.y;
		value = i.value;
		for (long long ii = tmp_y; ii > 1; ii--)
		{
			tmp_x++;
			tmp_y--;
			value++;
			v2.push_back({ tmp_x , tmp_y , value });
		}
	}

	long long tc,n1,n2;
	long long c, d;
	cin >> tc;
	for (long long ii = 0; ii < tc; ii++)
	{
		cin >> n1 >> n2;
		c = 0;
		d = 0;
		
		for (auto i : v2)
		{
			if (i.value == n1)
			{
				c = i.x;
				d = i.y;
				break;
			}
		}
		for (auto i : v2)
		{
			if (i.value == n2)
			{
				c += i.x;
				d += i.y;
				break;
			}
		}		
		for (auto i : v2)
		{
			if (i.x == c && i.y == d)
			{
				cout << i.value << "\n";
				break;
			}
		}
	}
	return 0;
}


