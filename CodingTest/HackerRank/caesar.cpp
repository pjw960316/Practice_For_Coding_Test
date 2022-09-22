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

string caesarCipher(string s, int k) 
{
    string ans = "";
    map<int, char> m1,m3;
    map<char, int> m2,m4;
    
    //1. map init
    //이거를 map 초기화라고 써서 HackerRank에서는 오류났음^^
    //외국 사이트는 한글 혐오함.
    int idx = 0;
    for(auto i = 'a'; i<='z'; i++)
    {
        m1.insert({idx,i});
        m2.insert({i,idx});
        idx++;
    }
    
    idx = 0;
    for(auto i = 'A'; i<='Z'; i++)
    {
        m3.insert({idx,i});
        m4.insert({i,idx});
        idx++;
    }
    
    for(auto i : s)
    {
        //2. small
        if('a' <= i && i <= 'z')
        {
            if(m2[i] + k > 25)
            {
                ans.push_back(m1[(m2[i]+k) % 26]);
            }
            else
            {
                ans.push_back(m1[m2[i]+k]);
            }
        }
        
        //3. big
        else if('A' <= i && i <= 'Z')
        {
            if(m4[i] + k > 25)
            {
                ans.push_back(m3[(m4[i]+k) % 26]);
            }
            else
            {
                ans.push_back(m3[m4[i]+k]);
            }
        }
        else
        {
            ans.push_back(i);
        }
    }
    return ans;

}
