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

int arr[1001];
vector<int> prime;
void MakePrimeNumber()
{
	memset(arr, 0, sizeof(arr));
	arr[0] = -1;
	arr[1] = -1;
	for (int i = 4; i <= 1000; i++)
	{
		for (int j = 2; j <= i / 2; j++)
		{
			if (i % j == 0)
			{
				arr[i] = -1;
			}
		}
	}
	for (int i = 2; i <= 1000; i++)
	{
		if (arr[i] == 0)
		{
			prime.push_back(i);
		}
	}

}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	MakePrimeNumber();

	int tc,num;
	bool can_out;
	cin >> tc;
	for (int i = 0; i < tc; i++)
	{
		can_out = false;
		cin >> num;
		for (auto i : prime)
		{
			for (auto j : prime)
			{
				for (auto k : prime)
				{
					if (i + j + k == num)
					{
						cout << i << " " << j << " " << k << "\n";
						can_out = true;
						break;
					}
				}
				if (can_out == true)
				{
					break;
				}
			}
			if (can_out == true)
			{
				break;
			}
		}
		if (can_out == false)
		{
			cout << 0 << "\n";
		}
	}
	
	return 0;
}