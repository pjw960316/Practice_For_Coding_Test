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
	int lv;
	int cnt;	
	vector<pair<string, int>> person;
};
vector<str> v;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	v.push_back({ 3,5 }); //�̰͸� �ص� v�� ���Ұ� �߰������� v[0]�� person ���ʹ� �� ���� ����
	//�Ұ��� : v.push_back({3,5,{"test_1" , 11});
	v[0].person.push_back({ "test_1", 11 });
	v[0].person.push_back({ "test_2" , 22 });

	for (int t = 0; t < 10; t++)
	{
		for (auto i : v)
		{
			i.cnt++;
			cout << i.lv << " " << i.cnt << " ";
			cout << "\nnested vector's instances : ";
			for (auto j : i.person)
			{
				cout << j.first << " " << j.second << " ";
			}
		}
	}
	return 0;
}
