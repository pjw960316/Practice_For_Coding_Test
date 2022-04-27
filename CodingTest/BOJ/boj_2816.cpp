#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <string>
#include <algorithm>
#include <utility>
#include <cmath>
#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#define ULL unsigned long long
using namespace std;

vector<string> v;
int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);

    int n;    
    string tmp , str;

    cin >> n;
    for(int i=0; i<n; i++)
    {
        cin >> str;
        v.push_back(str);
    }
    int cnt = 0;
    for(auto i : v)
    {        
        if(i == "KBS1" || i == "KBS2")
        {
            break;
        }
        cnt++;
        cout << "1";
    }
    for(int i=cnt; i>0; i--)
    {
        tmp = v[i];
        v[i] = v[i-1];
        v[i-1] = tmp;
        cout << "4";        
    }
    cnt = 0;
    cout << "1";
    for(int i=1; i<v.size(); i++)
    {        
        if(v[i] == "KBS1" || v[i] == "KBS2")
        {
            break;
        }
        cnt++;
        cout << "1";
    }
    for(int i=cnt+1; i>1; i--)
    {
        tmp = v[i];
        v[i] = v[i-1];
        v[i-1] = tmp;
        cout << "4";        
    }
    if(v[0] == "KBS2")
    {
        cout << "4";
        return 0;
    }
    
	return 0;
}
