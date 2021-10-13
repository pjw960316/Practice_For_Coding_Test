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
	int a;
	int b;
	int c;
};
vector<str> v;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	v.push_back({ 1,2,3 });

	//test_1
	cout << "TEST_1 : ";
	for (int i = 0; i < 5; i++)
	{				
		for (auto i : v)
		{
			i.a++;
			cout << i.a;
		}
	}

	cout << "\n\nTEST_2 : ";
	//test_2
	for (int i = 0; i < 5; i++)
	{		
		for (auto &i : v)
		{
			i.a++;
			cout << i.a;
		}
	}
	return 0;
}


