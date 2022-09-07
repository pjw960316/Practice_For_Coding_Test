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

int arr[503][503];

int main()
{
    int r,c;
    cin >> c >> r;
    for(int i=1; i<=r; i++)
    {
        int n;
        cin >> n;
        for(int j=1; j<=n; j++)
        {
            arr[i][j] = 1;
        }
    }

    int answer = 0;
    for(int i=1; i<=r; i++)
    {
        for(int j=1; j<=c; j++)
        {
            int tmp = 0;
            if(arr[i][j] == 0)
            {
                //위쪽 검사
                for(int a=1; a<1000; a++)
                {
                    if(arr[i-a][j] == 1)
                    {
                        tmp++;
                        break;
                    }
                    if(i-a <= 1)
                    {
                        tmp = -1000;
                        break;
                    }
                }

                //아래 검사
                for(int a=1; a<1000; a++)
                {
                    if(arr[i+a][j] == 1)
                    {
                        tmp++;
                        break;
                    }
                    if(i+a >= r)
                    {
                        tmp = -1000;
                        break;
                    }
                }
                if(tmp == 2)
                {
                    answer++;
                }
            }
        }
    }
    cout << answer;
    return 0;
}
   