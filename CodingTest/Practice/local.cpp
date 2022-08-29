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

int callByValue(vector<int> v)
{
    printf("cbv : %p\n" ,v);
    v[3] = 77;

}

void test(vector<int> &v)
{
    for(auto i : v)
    {
        cout << i << " " ;
    }
    
    v[4] = 12;
    cout << "\n";

}
int callByRefer(vector<int> &v)
{
    printf("cbr : %p\n" ,v);
    v[2] = 88;
    test(v);

}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> v;
    for(int i=0; i<5; i++)
    {
        v.push_back(i*10);
    }

    printf("local : %p\n" ,v);

    callByValue(v);
    callByRefer(v);

    for(auto i : v)
    {
        cout << i << " ";
    }

    
   return 0;
}