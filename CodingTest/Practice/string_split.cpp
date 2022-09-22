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

    string str = "Hello My name is John";
    vector<string> v;
    string tmp = "";

    //공백을 찾아서 구분하고 vector에 저장한다.
    for(auto i : str)
    {
        if(i == ' ')
        {
            v.push_back(tmp);
            tmp = "";
        }
        else
        {
            tmp.push_back(i);
        }
    }

    //마지막에 저장하지 않은 문자열까지 챙겨준다.
    if(tmp.length() != 0)
    {
        v.push_back(tmp);
    }

    for(auto i : v)
    {
        cout << i << "\n";
    }
    /*
    Hello
    My
    name
    is  
    John
    */

   return 0;
}