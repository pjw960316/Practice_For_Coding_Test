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

int n;
int arr[10000];
void Dfs(int depth)
{
    if(depth == n+1)
    {
        for(int i=1; i<=n; i++)
        {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }

    arr[0] = -11;
    bool is_dup = false;
    for(int i=1; i<=n; i++)
    {
        is_dup = false;
        for(int j=0; j<depth; j++)
        {
            if(arr[j] == i)
            {
                is_dup = true;
                break;
            }
        }
        if(is_dup == false)
        {
            arr[depth] = i;
            Dfs(depth+1);
        }
    }

}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    
    cin >> n;

    Dfs(1);

   return 0;
}