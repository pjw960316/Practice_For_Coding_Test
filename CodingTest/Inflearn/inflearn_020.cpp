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

int a[101];
int b[101];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for(int i=0; i<n; i++)
    {
        cin >> b[i];
    }
    for (int i = 0; i < n; i++)
    {
        if (a[i] == 1 && b[i] == 1)
        {
            cout << "D\n";
        }
        else if (a[i] == 1 && b[i] == 2)
        {
            cout << "B\n";
        }
        else if (a[i] == 1 && b[i] == 3)
        {
            cout << "A\n";
        }
        else if (a[i] == 2 && b[i] == 1)
        {
            cout << "A\n";
        }
        else if (a[i] == 2 && b[i] == 2)
        {
            cout << "D\n";
        }
        else if (a[i] == 2 && b[i] == 3)
        {
            cout << "B\n";
        }
        else if (a[i] == 3 && b[i] == 1)
        {
            cout << "B\n";
        }
        else if (a[i] == 3 && b[i] == 2)
        {
            cout << "A\n";
        }
        else if (a[i] == 3 && b[i] == 3)
        {
            cout << "D\n";
        }
    }
    return 0;
}