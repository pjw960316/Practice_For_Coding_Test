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


queue<int> q;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int me, cow;
    cin >> me >> cow;
    if (me == cow)
    {
        cout << 0;
        return 0;
    }
    q.push(me);
    
    int arr[20000];
    int move[3] = { 1,-1,5 };
    //1. 큐가 빌 때 까지 큐에 데이터는 쌓입니다.
    while (q.empty() == false)
    {
        int x = q.front();
        //2. 세 가지 경우 수행
        for (int i = 0; i < 3; i++)
        {
            if (x +move[i] <= 0 || x + move[i] > 10000)
            {
                continue;
            }
            if (x + move[i] == cow)
            {
                cout << arr[x] + 1;
                return 0;
            }
            else if(arr[x+ move[i]] == 0) //3. erase visit
            {
                arr[x + move[i]] = arr[x] + 1;
                q.push(x + move[i]);
            }
        }
        q.pop();
        
    }
    return 0;
}