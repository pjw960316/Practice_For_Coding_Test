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

int answer = 0;
unordered_map<string,bool> um;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m;
    cin >> n >> m;
    answer = n;

    string key_word = "";
    for(int i=0; i<n; i++)
    {
        cin >> key_word;
        um.insert({key_word , true});
    }

    string str = "";
    vector<string> v;
    for(int i=0; i<m; i++)
    {
        cin >> str;
        v.clear();
        string tmp = "";
        //vector에 문자열들 넣음
        for(int j=0; j<str.length(); j++)
        {
            if(str[j] == ',')
            {
                v.push_back(tmp);
                tmp = "";
            }
            else if(j == str.length()-1)
            {
                tmp.push_back(str[j]);
                v.push_back(tmp);
                break;
            }
            else
            {
                tmp.push_back(str[j]);
            }
        }
      
      //test code
        // for(auto k : v)
        // {
        //     cout << k << "    ";
        // }
        // cout << "\n";
        for(auto str : v)
        {
            //um에 있어
            if(um.find(str) != um.end())
            {
                if(um[str] == true)
                {
                    answer--;
                    um[str] = false;
                }
            }
        }
        cout << answer <<"\n";
    }

   return 0;
}