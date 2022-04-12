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

int a[10];
int b[10];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for (int i = 0; i < 10; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < 10; i++)
    {
        cin >> b[i];
    }
    int sum_a = 0 , sum_b=0;
    bool is_a_last = false;
    for (int i = 0; i < 10; i++)
    {
        if (a[i] > b[i])
        {
            sum_a += 3;
            is_a_last = true;
        }
        else if (a[i] < b[i])
        {
            sum_b += 3;
            is_a_last = false;
        }
        else
        {
            sum_a += 1;
            sum_b += 1;
        }
    }

    if (sum_a == 10 && sum_b == 10)
    {
        cout << sum_a << " " << sum_b << "\n";
        cout << "D";
        return 0;
    }
    if (sum_a == sum_b)
    {
        if (is_a_last == true)
        {
            cout << sum_a << " " << sum_b << "\n";
            cout << "A";
        }
        else
        {
            cout << sum_a << " " << sum_b << "\n";
            cout << "B";
        }
        return 0;
    }
    if (sum_a > sum_b)
    {
        cout << sum_a << " " << sum_b << "\n";
        cout << "A";
        return 0;
    }
    if (sum_a < sum_b)
    {
        cout << sum_a << " " << sum_b << "\n";
        cout << "B";
        return 0;
    }

   
    
    return 0;
}