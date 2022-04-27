#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <string>
#include <algorithm>
#include <utility>
#include <cmath>
#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#define ULL unsigned long long
using namespace std;

vector<char> color;
vector<int> num;
int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);

    char alpha;
    int number;
    for(int i=0; i<5; i++)
    {
        cin >>alpha >> number;
        color.push_back(alpha);
        num.push_back(number); 
    }
    sort(color.begin() , color.end());
    sort(num.begin() , num.end());

    //1.
    if(num[0]+4 == num[4] && color[0] == color[4])
    {
        cout << num[4] + 900;
        return 0;
    }
    //2.
    if(num[0] == num[3] || num[1] == num[4])
    {
        cout << num[2] + 800;
        return 0;        
    }
    //3.
    if(num[0] == num[2] && num[3] == num[4])
    {
        cout << num[0]*10 + num[3] +700; 
        return 0;
    }
    if(num[0] == num[1] && num[2] == num[4])   
    {
        cout << num[2]*10 + num[0] + 700;
        return 0;
    }
    //4. 
    if(color[0] == color[4])
    {
        cout << num[4] + 600;
        return 0;
    }
    //5. 
    if(num[0] + 4 == num[4])
    {
        cout << num[4] + 500;
        return 0;
    }
    //6.
    if(num[0] == num[2])
    {
        cout << num[0] + 400;
        return 0;
    }
    if(num[1] == num[3])
    {
        cout << num[1] + 400;
        return 0;
    }
    if(num[2] == num[4])
    {
        cout << num[2] + 400;
        return 0;
    }
    //7 ~ 9.
    int check = 0;
    vector<int> buffer;
    for(auto i : num)
    {
        check = 0;
        for(auto j : num)
        {
            if(i==j)
            {
                check++;
            }
        }
        if(check==2)
        {
            buffer.push_back(i);
        }
    }
    sort(buffer.begin() , buffer.end());
    if(buffer.size() == 4)
    {
        cout << buffer[3]*10 + buffer[1] + 300;
    }
    else if(buffer.size() == 2)
    {
        cout << buffer[0] + 200;
    }
    else
    {
        cout << num[4] + 100;
    }

	return 0;
}
