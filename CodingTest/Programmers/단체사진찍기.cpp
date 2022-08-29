#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <utility>
#include <cstdlib>

using namespace std;

map<char,int> m;
string friends;
int answer;
int arr[9];

void DFS(int depth , vector<string> &data)
{
    //depth 9일 때 검사를 한다.
    if(depth == 9)
    {
        bool is_answer = true;
        for(auto str : data)
        {
            char one = str[0];
            char two = str[2];
            int value = str[4] - '0' + 1; //문제를 제대로 읽지 못해서 +1을 하지 않았다.
          
            if(str[3] == '=')
            {
                if(abs(m[one] - m[two]) != value)
                {
                    is_answer = false;                  
                }
            }
            else if(str[3] == '>')
            {
                if(abs(m[one] - m[two]) <= value)
                {
                    is_answer = false;                 
                }
            }
            else
            {
                if(abs(m[one] - m[two]) >= value)
                {
                    is_answer = false;                   
                }
            }
        }
        if(is_answer == true)
        {
            answer++;
            return;
        }
        return;
    }
    
    //일반적인 DFS 순열
    bool is_dup = false;
    for(int i=0; i<8; i++)
    {
        is_dup = false;       
        for(int j=0; j<depth; j++) //이전 depth에 문제가 중복이 있다면 그 원소는 순열에 포함시키지 않는다.
        {
            if(arr[j] == friends[i])
            {
                is_dup = true;
                break;
            }
        }
        if(is_dup == false)
        {
            //필요한 자료구조에 값을 추가한다.
            arr[depth] = friends[i];
            m[friends[i]] = depth;
          
            DFS(depth+1 , data); //재귀 호출
        }
    }
}
int solution(int n, vector<string> data) 
{    
    friends = "ACFJMNRT";
    answer = 0;
    
    //1. 참고할 map과 arr를 초기화
    for(auto i : friends)
    {
        m.insert({i,-1});
    }
    for(int i=0; i<9; i++)
    {
        arr[i] = 0;
    }
    
    //2. DFS로 순열 -> 이거 라이브러리 메서드 있지만 기억 안 날 거임.
    DFS(1 , data);

    //DFS를 만들지 않고 순열을 나타내는 메서드가 존재하지만 기억 안나면 끝임.
  
    return answer;
}