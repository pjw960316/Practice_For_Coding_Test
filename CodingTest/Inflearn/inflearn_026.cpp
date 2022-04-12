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

int arr[10001];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //최대 가 5*10^7인데 문제에서 시간 관련 언급이 없음
    int n;
    int rate;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        rate = i;
        cin >> arr[i];
        for (int j = 1; j < i; j++)
        {
            if (arr[j] < arr[i])
            {
                rate--;
            }
        }
        cout << rate << " ";
    }
    return 0;
}