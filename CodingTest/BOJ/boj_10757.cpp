#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <algorithm>
#include <utility>
#include <cmath>
#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <list>
#include <deque>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <queue>

using ll = long long;
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string str1,str2;
    cin >> str1 >> str2;

    string ttmp = str1;
    if(str2.size() > str1.size())
    {
        str1 = str2;
        str2 = ttmp;
    }
    deque<int> answer;

    int start = str2.size()-1;
    int tmp = 0;
    int stored_value = 0;
    for(int i=str1.size()-1; i>=0; i--)
    {
        tmp = 0;
        tmp += str1[i] - '0';
        if(start >= 0)
        {
            tmp += str2[start] - '0';
            start--;
        }

        tmp += stored_value;
        if(i==0)
        {
            answer.push_front(tmp);
            for(auto jj : answer)
            {
                cout << jj;
            }
            return 0;
        }
        if(tmp >= 10)
        {
            tmp -= 10;    
            stored_value = 1;
        }
        else
        {
            stored_value = 0;
        }
        
        answer.push_front(tmp);
    }
    return 0;
}