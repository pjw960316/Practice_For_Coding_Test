#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <utility>
#include <sstream>
#include <fstream>

using namespace std;

string solution(string str) 
{
    string answer ="";
    string tmp1 = "" , tmp2 = "";
    //1.
    for(auto i : str)
    {
        tmp1.push_back(tolower(i));
    }
    cout << tmp1 <<"\n";
    //2.
    for(auto i : tmp1)
    {
        if(('a'<= i && i<='z') || ('0' <= i && i<='9') || i =='-' || i=='_' || i=='.')
        {
            tmp2.push_back(i);
        }
    }
    cout << tmp2 <<"\n";
    //3. 
    tmp1 = "";
    tmp1.push_back(tmp2[0]);
    for(int i=1; i<tmp2.length(); i++)
    {
        if(tmp2[i-1] == '.' && tmp2[i] == '.')
        {
            continue;
        }
        tmp1.push_back(tmp2[i]);
    }
    cout << tmp1 <<"\n";
    //4.
    tmp2 = "";
    for(int i=0; i<tmp1.length(); i++)
    {
        if(i == 0 || i == tmp1.length()-1)
        {
            if(tmp1[i] == '.')
            {
                continue;
            }
        }
        tmp2.push_back(tmp1[i]);
    }
    cout << tmp2 << "\n";
    //5.
    if(tmp2 == "")
    {
        tmp2 = "a";
    }
    
    cout << tmp2 << "\n";
    //6. 
    tmp1 = "";
    if(tmp2.length() < 16)
    {
        tmp1 = tmp2;
    }
    else
    {
        for(int i=0; i<15; i++)
        {
            tmp1.push_back(tmp2[i]);
        }
    
        if(tmp1[14] == '.')
        {
            tmp1.pop_back();
        }
    }
    cout << tmp1 << "\n";
    //7.
    tmp2 = "";
    if(tmp1.length() <= 2)
    {
        tmp1.push_back(tmp1[tmp1.length()-1]);
    }
    if(tmp1.length() <= 2)
    {
        tmp1.push_back(tmp1[tmp1.length()-1]);
    }
    
    cout << tmp1 << "\n";
    answer = tmp1;
    return answer;
}