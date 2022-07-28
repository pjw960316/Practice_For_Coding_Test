#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

int arr1[5] = {1,2,3,4,5};
int arr2[8] = {2,1,2,3,2,4,2,5};
int arr3[10] = {3,3,1,1,2,2,4,4,5,5};
int ans1 = 0 , ans2 = 0 , ans3 = 0;

vector<int> solution(vector<int> answers) 
{
    vector<int> answer;
    
    int idx = 0;
    for(auto i : answers)
    {
        if(i == arr1[idx % 5])
        {
            ans1++;
        }
        if(i == arr2[idx % 8])
        {
            ans2++;
        }
        if(i == arr3[idx % 10])
        {
            ans3++;
        }
        idx++;
    }
    
    vector<pair<int,int>> v;
    v.push_back({ans1,1});
    v.push_back({ans2,2});
    v.push_back({ans3,3});

    sort(v.begin() , v.end());
    reverse(v.begin() , v.end());
    
    cout <<v[0].first << " " <<v[1].first << " " << v[2].first;
    answer.push_back(v[0].second);
    if(v[0].first == v[1].first)
    {
        answer.push_back(v[1].second); 
        if(v[1].first == v[2].first)
        {
            answer.push_back(v[2].second);  
            sort(answer.begin() , answer.end());
            return answer; 
        }
    }
    sort(answer.begin() , answer.end());
    return answer;
       
}