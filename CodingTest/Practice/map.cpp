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

//0. initialize
map<string, int> m;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	//1. insert
	m.insert({ "aaa" , 1500 });
	m.insert({ "bbb" , 2500 });
	m.insert({ "ccc" , 600 });
	m.insert({ "ddd" , 7000 });
	m.insert({ "eee" , 1000 });

	//2. print map's instances
	cout << "1. Print Map Data\n";
	for (auto i : m)
	{
		cout << i.first << " " << i.second << "\n";
	}
		
	//3. erase using key
	m.erase("ccc");
	cout << "\n2.erase ccc\n";
	for (auto i : m)
	{
		cout << i.first << " " << i.second << "\n";
	}

	//4. find using key
	cout << "\n3. find\n";
	if (m.find("aaa") != m.end())
	{
		cout << "find!\n";
	}
	else
	{
		cout << "find x!\n";
	}

	//5. find key using value
	for (auto i : m)
	{
		if (i.second == 7000)
		{
			cout << "\n4.value is 7000 , and what is key? , answer : " << i.first;
			cout << endl;
		}
	}

	//6. change value using key
	m["bbb"] = 12000;
	cout << "\n5. bbb's value changed\n";
	for (auto i : m)
	{
		cout << i.first << " " << i.second << "\n";
	}	

	/*
	7. change key
		1) eliminate origin instance
		2) insert new instance
	*/
	m.erase("bbb");
	m.insert({ "BBB" , 12000 });
	cout << "\n6. value : 12000's key was bbb , but now BBB\n";
	for (auto i : m)
	{
		cout << i.first << " " << i.second << "\n";
	}

	return 0;
}


