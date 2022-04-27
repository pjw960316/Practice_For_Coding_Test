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

int arr[701][701];
int ans = -1;
int tmp1, tmp2;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int r, c;
    cin >> r >> c;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> arr[i][j];
        }
    }

    int a, b;
    cin >> a >> b;
    int base = 0;
   
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            int left = 0, right = 0;

            if (i + a > r || j + b > c)
            {
                break;
            }
            //base ±¸ÇÏ±â
            if (j == 0)
            {
                base = 0;
                for (int ii = 0; ii < a; ii++)
                {
                    for (int jj = 0; jj < b; jj++)
                    {
                        base += arr[i + ii][j + jj];
                        
                    }
                }   
            }
            else
            {
                left = 0;
                right = 0;
                for (int k = 0; k < a; k++)
                {
                    left += arr[i + k][j-1];
                }
                for (int k = 0; k < a; k++)
                {
                    right += arr[i + k][j + b - 1];
                }
            }
            base = base - left + right;
            //cout << left << " " << right << " " <<base << "\n";
            if (base > ans)
            {
                tmp1 = i;
                tmp2 = j;
                ans = base;
            }
        }
    }

    cout << ans;

    return 0;
}