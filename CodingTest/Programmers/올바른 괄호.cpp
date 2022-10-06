#include <string>
#include <iostream>

using namespace std;

bool solution(string s)
{

    int left = 0;
    int right = 0;
    for(auto i : s)
    {
        if(left < right)
        {
            return false;
        }
        
        if(i == '(')
        {
            left++;
        }
        else
        {
            right++;
        }
    }
    if(left != right)
    {
        return false;
    }

    return true;   
}