#include <string>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>
#include <utility>

using namespace std;

/*
코딩의 난해함은 전혀 없었으나 문제를 잘못 읽었다.
*/

int solution(string str1, string str2) 
{
    //1. 소문자 -> 대문자
    string str3 = "";
    string str4 = "";
    for(auto i : str1)
    {
        if('a' <= i && i <= 'z')
        {
            str3.push_back(i - 0x20);
        }
        else
        {
            str3.push_back(i);
        }
    }
    for(auto i : str2)
    {
        if('a' <= i && i <= 'z')
        {
            str4.push_back(i - 0x20);
        }
        else
        {
            str4.push_back(i);
        }
    }
    
    //2. 문자열 나누기
    vector<string> v1,v2;
    string tmp = "";
    int cnt = 0;
    for(int i=0; i<str3.length()-1; i++)
    {
        tmp = "";
        if(('A' <= str3[i] && str3[i] <='Z') && ('A' <= str3[i+1] && str3[i+1] <='Z'))
        {
            tmp.push_back(str3[i]); 
            tmp.push_back(str3[i+1]);
            v1.push_back(tmp);         
        }
    }
    
    for(int i=0; i<str4.length()-1; i++)
    {
        tmp = "";
        if(('A' <= str4[i] && str4[i] <='Z') && ('A' <= str4[i+1] && str4[i+1] <='Z'))
        {
            tmp.push_back(str4[i]); 
            tmp.push_back(str4[i+1]);
            v2.push_back(tmp);         
        }
    }
    
    
    //3. 교집합 , 합집합
    set<string>s;
    map<string,int>m1,m2;
    for(auto i : v1)
    {
        s.insert(i);
    }
    for(auto i : v2)
    {
        s.insert(i);
    }
    for(auto i : v1)
    {
        if(m1.find(i) == m1.end())
        {
            m1.insert({i,1});
        }
        else
        {
            m1[i]++;
        }
    }
    for(auto i : v2)
    {
        if(m2.find(i) == m2.end())
        {
            m2.insert({i,1});
        }
        else
        {
            m2[i]++;
        }
    }
    
    //float -> int
    int mmin = 0;
    int mmax = 0;
    for(auto i : s)
    {
        mmin += min(m1[i] , m2[i]);
        mmax += max(m1[i] , m2[i]);
    }
    if(mmin == 0 && mmax == 0)
    {
        return 65536;
    }
    float tmp_ans = (float)mmin / (float)mmax * 65536;
    int answer = tmp_ans;
    return answer;
}