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

vector<int> v;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;
    for (int i = 0; i < 15; i++)
    {
        if (pow(k, i) > 1000)
        {
            break;
        }
        v.push_back(pow(k, i));
    }

    string str = "";

    for (int i = v.size() - 1; i >= 0; i--)
    {
        if (n < v[i] && str.length() == 0)
        {
            continue;
        }
        if (n < v[i] && str.length() != 0)
        {
            str += '0';
            continue;
        }
        if (k == 16)
        {
            int tmp = n / v[i];
            if (n / v[i] == 10)
            {
                str += 'A';
            }
            else if (n / v[i] == 11)
            {
                str += 'B';
            }
            else if (n / v[i] == 12)
            {
                str += 'C';
            }
            else if (n / v[i] == 13)
            {
                str += 'D';
            }
            else if (n / v[i] == 14)
            {
                str += 'E';
            }
            else if (n / v[i] == 15)
            {
                str += 'F';
            }
            else
            {
                str += tmp + '0';                
            }
            n -= tmp * v[i];
        }
        else
        {
            int tmp = n / v[i];
            str += tmp + '0';
            n -= tmp * v[i];
        }
    }    

    cout << str;
    return 0;
}