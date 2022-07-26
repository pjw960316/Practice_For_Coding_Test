#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) 
{
    string answer = "";
    unordered_map<string,int> um;
    
    for(auto name : completion)
    {
        if(um.find(name) == um.end())
        {
            um.insert({name,1});
        }
        else
        {
            um[name] += 1;
        }
    }
    
    for(auto name : participant)
    {
        if(um.find(name) == um.end() || um[name] == 0)
        {
            answer = name;
            break;
        }
        else
        {
            um[name] -= 1;
        }
    }
    return answer;
}