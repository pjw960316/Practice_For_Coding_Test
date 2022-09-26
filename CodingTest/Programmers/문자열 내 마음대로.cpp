#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <iostream>

using namespace std;

int gn;
bool compare(string str1 , string str2)
{
    if(str1[gn] == str2[gn])
    {
        return str1 < str2;
    }
    else
    {
        return str1[gn] < str2[gn];
    }
}
vector<string> solution(vector<string> strings, int n) 
{
    gn = n;
    vector<string> answer;
    
    sort(strings.begin() , strings.end() , compare);
    for(auto i : strings)
    {
        answer.push_back(i);
    }
    
    return answer;
}