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

int arr[9]; 
int visit[9];
int buffer[9];
int len;
int answer = 0;

int Sum(int depth)
{
    int result = 0;   
    for(int i=0; i<=depth-2; i++)
    {
        result += abs(buffer[i]-buffer[i+1]);
    }  
    return result;
}
void GetAllCase(int depth)
{
    if(depth==len)
    {
        int buffer_sum = 0;
        buffer_sum = Sum(depth);
        if(answer < buffer_sum)
        {
            answer = buffer_sum;
        }
    }
    else
    {
        for(int i=0; i<len; i++)
        {
            if(visit[i] == 0)
            {
                visit[i] = 1;
                buffer[depth] = arr[i]; 
                GetAllCase(depth+1);
                visit[i] = 0; //ÇÙ½É
            }
        }
    }
}
int main()
{
    int n;
    cin >> n;
    len = n;
    for(int i=0; i<n; i++)
    {
        cin >> arr[i];
    }
    GetAllCase(0);
    cout << answer;

	return 0;
}