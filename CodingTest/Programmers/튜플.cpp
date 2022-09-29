#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>
#include <utility>
#include <cstring>

using namespace std;

// 문자열을 가공하는 방식이 조금 미숙하지만 풀이 방식은 다른 이들의 코드와 비슷.
// 가공_1과 가공_2를 한 번에 처리하는 경우가 많았다.
// 빈 map을 만드는 것에 대한 미숙함이 있었다.

map<int,vector<string>> m;
map<string,int> m2; //이건 그냥 vector로 했어도 됐음

vector<int> solution(string s) 
{
    vector<int> answer;
    
    //0. 빈 맵 구현
    vector<string> tmp_v;
    for(int i=1; i<=100000; i++)
    {
        m.insert({i,tmp_v});
    }
    for(int i=1; i<=100000; i++)
    {
        string tmp = to_string(i);
        m2.insert({tmp,0}); // 0 = non - visit
    }
    
    //1. 양날개 제거
    s.erase(0,1);
    s.erase(s.length()-1 , 1);
    
    //2. 가공_1
    vector<string> v;
    string str = "{";
    for(int i=1; i<s.length(); i++)
    {
        str += s[i];
        if((s[i-1] == '}' && s[i] == ',') || i == s.length()-1)
        {
            if(str[str.length()-1] == ',')
            {
                str.pop_back();
            }
            v.push_back(str);
            str = "";
        }       
    }
 
    //3. 가공_2
    for(auto i : v)
    {
        string str = i;
        str.erase(0,1);
        str.erase(str.length()-1,1);
        
        vector<string> vv;
        vv.clear();
        
        string tmp = "";
        for(int j=0; j<str.length(); j++)
        {
            if(str.length() == 1)
            {
                vv.push_back(str);
                break;
            }
            if(j == str.length()-1)
            {
                tmp.push_back(str[j]);
                vv.push_back(tmp);
                tmp = "";
                break;
            }
            if(str[j] == ',')
            {
                vv.push_back(tmp);
                tmp = "";
            }
            else
            {
                tmp.push_back(str[j]);
            }
        }
        
        int length = vv.size();
        for(auto k : vv)
        {
            m[length].push_back(k);
        }     
    }
    
    for(auto i : m)
    {
        for(auto j : i.second)
        {
            if(m2[j] == 0)
            {
                answer.push_back(stoi(j));
                m2[j] = 1;
            }
        }
    }
    return answer;
}