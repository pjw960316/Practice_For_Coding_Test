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

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	map<string, int> m;
	m.insert({ "aaa",1 });
	m.insert({ "bbb",2 });
	m.insert({ "ccc",3 });

	if (m.find("bbb") != m.end())
	{
		cout << "bbb is in map";
	}
	
	return 0;
}