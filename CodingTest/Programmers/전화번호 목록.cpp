#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

unordered_map<string,int> m;
bool solution(vector<string> phone_book) 
{
    bool answer = true;
    
    //중복 검사
    for(auto str : phone_book)
    {
        m.insert({str,true});
    }
    for(auto str : phone_book)
    {
        //길이가 1인 것도 만족. 같은 번호는 없기 때문
        for(int i=1; i<str.length(); i++)
        {
            string tmp = "";
            tmp = str.substr(0,i);
            if(m.find(tmp) != m.end())
            {
                return false;
            }
        }
    }
    
    return true;
}