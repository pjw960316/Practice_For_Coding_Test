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

double getDistance(int x1,int y1 , int x2, int y2)
{
    double tmp = (double)(pow((x2-x1) , 2) + pow((y2-y1) , 2)); 
    return sqrt(tmp);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int tc,x1,y1,r1,x2,y2,r2;
    cin >> tc;
    for(int i=0; i<tc; i++)
    {
        cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
        double dis = getDistance(x1,x2,y1,y2);

        //중점 같을 때
        if(dis == 0 && r1 == r2)
        {
            cout << -1 << "\n";
            continue;
        }
        if(dis == 0 && r1 != r2)
        {
            cout << 0 << "\n";
            continue;
        }
        
        //밖에서 만나지 않음
        if(dis > r1 + r2)
        {
            cout << 0 << "\n";
            continue;
        }
        //외접
        if(dis == r1 + r2)
        {
            cout << 1 << "\n";
            continue;
        }
        //내접
        if(dis == abs(r1-r2))
        {
            cout << 1 << "\n";
            continue;
        }
        //포함 되지 않고 두 군데서 만남
        if(dis < r1+ r2 && abs(r1-r2) < dis)   
        {
            cout << 2 << "\n";
            continue;
        }
        //안에 포함
        if(dis < abs(r1-r2))
        {
            cout << 0 << "\n";
            continue;
        }
        
    }

   return 0;
}