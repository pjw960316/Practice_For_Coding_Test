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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tc;
    cin >> tc;

    int x1,y1,x2,y2;
    int cnt;
    int x,y,r;
    int answer = 0;
    for(int i=0; i<tc; i++)
    {
        answer = 0;
        cin >> x1 >> y1 >> x2 >> y2;
        cin >> cnt;
        //하나 밖 / 하나 안
        //걸친 경우는 입력에 없다.
        for(int j=0; j<cnt; j++)
        {
            cin >> x >> y >> r;
            if(pow(x-x1,2) + pow(y-y1,2) < r*r && pow(x-x2,2) + pow(y-y2,2) > r*r)
            {
                answer++;
            }
            if(pow(x-x1,2) + pow(y-y1,2) > r*r && pow(x-x2,2) + pow(y-y2,2) < r*r)
            {
                answer++;
            }
        }
        cout << answer <<"\n";
    }

    return 0;
}