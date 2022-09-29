#include <string>
#include <vector>
#include <iostream>
#include <set>
#include <unordered_set>

using namespace std;

unordered_set <string> s;
vector<int> solution(int n, vector<string> words) 
{
    vector<int> answer;
    int round = 1;
    int person = 1;
    string before_word = "";
    before_word.push_back(words[0][0]);
    s.insert(before_word);
        
    for(auto cur_word : words)
    {
        //1. 끝말 실패
        if(before_word[before_word.length()-1] != cur_word[0])
        {
            answer.push_back(person);
            answer.push_back(round);
            break;
        }
        
        //2. 중복
        if(s.find(cur_word) != s.end())
        {
            answer.push_back(person);
            answer.push_back(round);
            break;
        }
        
        //3. 조건 형성
        s.insert(cur_word);
        before_word = cur_word;
        
        //4. 반복문 진행
        person += 1;
        if(person == n+1)
        {
            person = person % n;
            round++;
        }
    }
    
    if(answer.size() == 0)
    {
        answer.push_back(0);
        answer.push_back(0);
    }
    
    return answer;
}