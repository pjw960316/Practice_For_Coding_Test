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

int arr[3][3];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    memset(arr,-1,sizeof(arr));
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            cout << arr[i][j] << " ";
        }
    }

    string a = "abc";
    string b = "abd";
    if(a>b)
    {
        cout << "hi";
    }
   return 0;
}