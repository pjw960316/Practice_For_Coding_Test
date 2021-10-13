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


queue<int> q1, q2 , q3;
stack<int> s1;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n,num;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		q1.push(num);	
		s1.push(num);
	}
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		q2.push(num);		
	}
	while (s1.empty() != true)
	{
		q3.push(s1.top());
		s1.pop();
	}
	
	int tmp;
	for (int i = 0; i < n+1; i++)
	{			
		if (q1 == q2)
		{
			cout << "good puzzle";
			return 0;
		}
		tmp = q1.front();
		q1.pop();
		q1.push(tmp);

		if (q3 == q2)
		{
			cout << "good puzzle";
			return 0;
		}
		tmp = q3.front();
		q3.pop();
		q3.push(tmp);		
	}
	cout << "bad puzzle";
	
	return 0;
}