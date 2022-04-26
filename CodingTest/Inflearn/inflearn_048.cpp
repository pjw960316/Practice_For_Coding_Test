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
double arr[9][9];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < 9; i++)
    {
        double sum = 0;
        double similar = 10000;
        double tmp2 = -1;
        for (int j = 0; j < 9; j++)
        {
            sum += arr[i][j];
        }
        double avg = (floor)((sum / 9.0)+0.5);

        for (int j = 0; j < 9; j++)
        {
            double tmp = abs(arr[i][j] - avg);           
            if (tmp < similar)
            {
                similar = tmp;
                tmp2 = arr[i][j];
            }
            if (tmp == similar)
            {
                if (arr[i][j] > tmp2)
                {
                    tmp2 = arr[i][j];
                }
            }
        }
        cout << avg << " " << tmp2 << "\n";
    }

    return 0;
}