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

using namespace std;

int ancestor[1001];

int FindAncestor(int child)
{
    if(ancestor[child] == child)
    {
        return child;
    }
    else
    {
        return FindAncestor(ancestor[child]);
    }
}
int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	
    int v,e,n1,n2;
    cin >> v >> e;
    for(int i=1; i<=v; i++)
    {
        ancestor[i] = i;
    }
    vector<pair<int,int>> vec;
    for(int i=0; i<e; i++)
    {
        cin >> n1 >> n2;
        vec.push_back({n1,n2});
    }
    for(int i=0; i<e; i++)
    {
        n1 = vec[i].first;
        n2 = vec[i].second;
        //if(n1>n2) : 여기서 틀림
        if(ancestor[n1] < ancestor[n2])
        {
            ancestor[n2] = FindAncestor(n1);
        }
        else
        {
            ancestor[n1] = FindAncestor(n2);
        }        
    }
    for(int i=e-1; i>=0; i--)
    {
        n1 = vec[i].first;
        n2 = vec[i].second;
        //if(n1>n2) : 여기서 틀림
        if(ancestor[n1] < ancestor[n2])
        {
            ancestor[n2] = FindAncestor(n1);
        }
        else
        {
            ancestor[n1] = FindAncestor(n2);
        }        
    }

    /*cout << "\n\n";
    for(int i=1; i<=v; i++)
    {
        cout << i << " " <<ancestor[i] <<endl;
    }*/

    set<int> s;
    for(int i=1; i<=v; i++)
    {
        s.insert(ancestor[i]);
    }
    cout << s.size();
	return 0;
}


