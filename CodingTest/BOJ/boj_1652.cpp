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

int arr[101][101];
int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);

    int n;
    string str;
    cin >> n;
    for(int i=0; i<n; i++)
    {
        cin >> str;
        for(int j=0; j<n; j++)
        {
            arr[i][j] = str[j];
        }
    }

    int cnt = 0;
    int row_answer = 0 , col_answer = 0;
    
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(arr[i][j] == '.')
            {
                cnt++;
            }
            else
            {
                if(cnt>=2)
                {
                    row_answer++;   
                }
                cnt = 0;
            }
        }
        if(cnt>=2)
        {
            row_answer++;            
        }
        cnt = 0;
    }

    cnt = 0;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(arr[j][i] == '.')
            {
                cnt++;
            }
            else
            {
                if(cnt>=2)
                {
                    col_answer++;                 
                }
                cnt = 0;
            }
        }
        if(cnt>=2)
        {
            col_answer++;            
        }
        cnt = 0;
    }
    cout << row_answer << " " <<col_answer;    
	return 0;
}
