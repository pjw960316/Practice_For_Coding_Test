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

int nn;

void Dfs(int n)
{
    cout << n << " ";
    if (n == nn)
    {
        return;
    }    
    Dfs(n + 1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
        
    cin >> nn;
    Dfs(1);
    return 0;
}