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

queue<int> q;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		q.push(i);
	}
	
	cout << "<";
	int tmp;
	while (q.empty() == false)
	{
		for (int i = 0; i < k; i++)
		{	
			tmp = q.front();
			if (i != k - 1)
			{				
				q.push(tmp);
			}
			else
			{
				if (q.size() == 1)
				{
					cout << tmp;
				}
				else
				{
					cout << tmp << ", ";
				}
			}
			q.pop();			
		}
	}
	cout << ">";
	return 0;
}