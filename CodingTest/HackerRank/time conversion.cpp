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

using namespace std;

/*
 * Complete the 'timeConversion' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string timeConversion(string s) 
{
    string ans = "";
    
    string hour = s.substr(0,2);
    string org = s.substr(2,6);
    string ampm = s.substr(8,2);
    
    if(ampm == "AM")
    {
        if(hour == "12")
        {
            ans += "00";
        }
        else
        {
            ans += hour;
        }
    }
    else
    {
        if(hour == "12")
        {
            ans += hour;
        }
        else
        {
            string tmp = to_string(stoi(hour) + 12);
            ans += tmp;
        }
    }
   
    ans += org;
    return ans;
}