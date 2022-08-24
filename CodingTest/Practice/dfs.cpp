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

int arr[6];
void Dfs(int depth)
{
    if(depth == 0)
    {
        Dfs(1);
    }
    if(depth == 6)
    {
        for(int i=1; i<= 5; i++)
        {
            cout << arr[i] << " ";
        }
        cout <<"\n";
        return;
    }
    for(int i=1; i<=5; i++)
    {
        for(int j=0; j<depth; j++)
        {
            if(arr[j] != i)
            {
                arr[depth] = i;
                Dfs(depth+1);
            }
        }
    }

}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Dfs(0);

   return 0;
}