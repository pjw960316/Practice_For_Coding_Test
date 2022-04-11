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
string str;

void DoRecursion(int start , int end)
{
	int cur_start = start + ((end-start) / 3);
	int cur_end = start + ((end-start) / 3 * 2);
	for (int i = cur_start; i < cur_end; i++)
	{
		str[i] = ' ';
	}
	if (cur_end - cur_start == 1)
	{
		return;
	}
	else
	{
		DoRecursion(start, cur_start);
		DoRecursion(cur_start, cur_end);
		DoRecursion(cur_end, end);
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	while (1)
	{		
		cin >> n;
		if (cin.eof() == true)
		{
			break;
		}
		if (n == 0)
		{
			cout << "-\n";
			continue;
		}
		n = pow(3, n);
		str.clear();
		for (int i = 0; i < n; i++)
		{
			str.push_back('-');
		}
		DoRecursion(0, n);
		cout << str << "\n";		
	}	

	return 0;
}


