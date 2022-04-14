#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <algorithm>
#include <utility>
#include <cmath>
#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <list>
#include <deque>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <queue>

using ll = long long;
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	int n, left = 77, right, cur, k = 1, res = 0;
	cin >> n;
	while (left != 0)
	{
		left = n / (k * 10);
		right = n % k;
		cur = (n / k) % 10;
		if (3 < cur)
		{
			res = res + ((left + 1) * k);
		}
		else if (3 == cur)
		{
			res = res + ((left * k) + (right + 1));
		}
		else res = res + (left * k);
		k = k * 10;
	}
	cout << res;
	
    return 0;
}