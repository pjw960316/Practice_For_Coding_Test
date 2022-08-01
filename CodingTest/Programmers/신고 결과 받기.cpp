#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <iostream>

using namespace std;

unordered_map<string,unordered_set<string>> m1;
unordered_map<string,int> m2;

vector<int> solution(vector<string> id_list, vector<string> report, int k) 
{
    //0. m1,m2 초기화
    unordered_set<string> s;
    for(auto i : id_list)
    {
        m1.insert({i,s});
    }
    
    for(auto i : id_list)
    {
        m2.insert({i,0});
    }
    vector<int> answer;
    
    for(auto i : report)
    {
        string str1 ="";
        string str2 ="";
        bool is_check = false;
        for(auto j : i)
        {
            if(j == ' ')
            {
                is_check = true;
            }
            if(is_check == false)
            {
                str1 += j;
            }
            else
            {
                str2 += j;
            }
        }
        
        //1. 신고자 map과 신고된 map에 데이터를 넣어줌.
        if(m1[str1].find(str2) == m1[str1].end())
        {
            m1[str1].insert(str2);
            m2[str2]++;
        }
    }
    
    map<string,int> m4;
    for(auto i : m1)
    {
        int tmp = 0;
        for(auto j : i.second)
        {
            if(m2[j] >= k)
            {
                tmp++;
            }
        }
        m4.insert({i.first,tmp});
    }
    
    for(auto i : id_list)
    {
        answer.push_back(m4[i]);
    }
    return answer;
}