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

int arr[1001];
map<int,int> prime;
void FindPrime()
{    
    for (int i = 2; i <= 500; i++)
    {
        for (int j = 2; j <= 500; j++)
        {
            if (i * j > 1000)
            {
                break;
            }
            arr[i * j] = -1;
        }
    }
    for (int i = 2; i <= 1000; i++)
    {
        if (arr[i] == 0)
        {
            prime.insert({ i,0 });
        }
    }    
}

void Check(int n)
{
    vector<int> v;
    for (auto i : prime)
    {
        if (i.first <= n)
        {
            v.push_back(i.first);
        }
    }
    for (auto i : v)
    {
        while (n % i == 0)
        {
            prime[i]++;
            n /= i;
            if (n == 1)
            {
                return;
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
        
    FindPrime();

    int n;
    cin >> n;
    for (int i = 2; i <= n; i++)
    {
        Check(i);
    }

    cout << n << "! = ";
    for (auto i : prime)
    {
        if (i.first > n)
        {
            return 0;
        }
        cout << i.second << " ";
        
    }
    return 0;
}