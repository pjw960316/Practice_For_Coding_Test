#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

map<string,vector<int>> m;

//스파이가 아무것도 안 입고 선글라스만 착용하는 비정상적인 것도 조건에 포함된다.
//실수는 하지 않았지만 비정상적인 세계를 이해하는 데에 조금 걸렸다.
int solution(vector<vector<string>> clothes) 
{
    vector<int> tmp;
    //1. make easy map
    for(int i=0; i<clothes.size(); i++)
    {   
        string key = clothes[i][1];
        if(m.find(key) == m.end())
        {
            tmp.clear();
            tmp.push_back(0); //null
            tmp.push_back(1);
            m.insert({key,tmp});
        }
        else
        {
            m[key].push_back(1);
        }
    }
    
    int answer = 1;
    for(auto i : m)
    {
        answer *= i.second.size();        
    }
    answer--;
    
    return answer;
}