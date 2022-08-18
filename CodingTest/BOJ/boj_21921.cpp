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

map<int,int> m;
int arr[250001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int x,n;
    cin >> x >> n;
    
    for(int i=0; i<x; i++)
    {
        cin >> arr[i];
    }

    int sum = 0;
    int mmax = -1;

    for(int j=0; j<n; j++)
    {
        sum += arr[j];
    }
    mmax = sum;
    m.insert({mmax,1});
    int end = n-1;

    for(int i=0; i<=x-n; i++)
    {
        end++;
        sum -= arr[i];
        sum += arr[end];
        
        if(m.find(sum) == m.end())
        {
            m.insert({sum,1});
        }
        else
        {
            m[sum]++;
        }
        if(mmax < sum)
        {
            mmax = sum;
        }
    }

    if(mmax == 0)
    {
        cout << "SAD";
        return 0;
    }
    cout << mmax << "\n";
    cout << m[mmax] << "\n";

   return 0;
}