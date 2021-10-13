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


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	vector<int> arr[5];

	//using pointer to clear -> X
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			arr[i].push_back(i+j);
		}
	}
	for (int i = 0; i < 5; i++)
	{
		for (auto j : arr[i])
		{
			cout << j << " ";
		}
		cout << "\n";
	}

	arr->clear();

	for (int i = 0; i < 5; i++)
	{
		for (auto j : arr[i])
		{
			cout << j << " ";
		}
		cout << "\n";
	}

	
	return 0;
}


