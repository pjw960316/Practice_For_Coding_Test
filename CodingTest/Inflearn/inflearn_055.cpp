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

int arr[31];
stack<int> s;
vector<int> v;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    string str = "";
    s.push(arr[0]);
    str += 'P';

    for (int i = 1; i < n; i++)
    {
        while (1)
        {            
            if (arr[i] < s.top())
            {
                s.push(arr[i]);
                str += 'P';
                break;
            }
            if (arr[i] > s.top())
            {
                v.push_back(s.top());
                str += 'O';
                s.pop();
            }
            if (s.empty() == true)
            {
                s.push(arr[i]);
                str += 'P';
                break;
            }            
        }

        if (i == n-1)
        {
            while (s.size() != 0)
            {
                v.push_back(s.top());
                str += 'O';
                s.pop();
            }
        }
    }

    bool is_impossible = false;
    for (int i = 0; i < v.size()-1; i++)
    {
        if (v[i] > v[i + 1])
        {
            is_impossible = true;
            break;
        }
    }

    if (is_impossible == true)
    {
        cout << "impossible";
    }
    else
    {
        cout << str;
    }
    return 0;
}