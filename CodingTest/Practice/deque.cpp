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
using ll = long long;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	deque<int> d;
	for (int i = 0; i < 5; i++)
	{
		d.push_back(i);
	}
		
	d.pop_front(); //�տ� ����(0)�� ����
	d.pop_back(); //�ڿ� ����(4)�� ����
	d.push_front(7); //�տ� 7�� �ֱ�
	d.push_back(7); //�ڿ� 7�� �ֱ�
	

	for (auto i : d)
	{
		cout << i << " ";
	}
	return 0;
}


