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

int m;
int ans = -1;
void BinarySearch(int s , int e)
{

    if (e <= s)
    {
        //cout << ans;
        return;
    }
    int mid = (s + e) / 2;

    cout << mid << "\n";
    int cnt = 1;
    int tmp = 0;
    for (int i = 0; i < v.size(); i++)
    {
        if (tmp + v[i] > m)
        {
            cnt++;
            tmp = v[i];
        }
        else
        {
            tmp += v[i];
        }
    }
    if (tmp < mid)
    {
        cnt++;
    }
 
    if (cnt > m)
    {
        BinarySearch(mid+1 , e);
    }
    else if(cnt < m)
    {
        BinarySearch(s, mid - 1);
    }
    else
    {
        ans = mid;
        cout << "ans" << mid << "\n";
        BinarySearch(s, mid - 1);
    }
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n >> m;

    int num;
    

    for (int i = 0; i < n; i++)
    {
        cin >> num;
        v.push_back(num);
    }
    
    int end = 0;
    for (auto i : v)
    {
        end += i;
    }

    BinarySearch(1, end);


    

    return 0;
}