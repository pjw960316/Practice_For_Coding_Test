#include <string>
#include <vector>
#include <map>
#include <set>
#include <iostream>

using namespace std;

map<double,set<int>> m;
vector<int> solution(int n, vector<int> stages) 
{
    vector<int> answer;
    vector<int> v1(501,0);
    vector<int> v2(501,0);
    for(auto i : stages)
    {
        for(int j =1; j<=i; j++)
        {
            v1[j] += 1;
        }
        v2[i] += 1;
    }
    
    for(int i=1; i<=n; i++)
    {
        double fail = (double)v2[i] / (double)v1[i];
        if(m.find(fail) == m.end())
        {
            set<int> s;
            s.insert(i);
            m.insert({fail,s});
        }
        else
        {
            m[fail].insert(i);
        }
    }
    
    for(auto i : m)
    {
        cout << "key : " <<i.first << " value : ";
        for(auto j : i.second)
        {
            cout << j << " ";
        }
        cout << "\n";
    }
    
    for(auto iter = m.rbegin(); iter != m.rend(); iter++)
    {
        auto tmp = *iter;
        for(auto i : tmp.second)
        {
            answer.push_back(i);
        }
    }
    
    return answer;
}