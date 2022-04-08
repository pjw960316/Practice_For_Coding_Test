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

int arr[100001];

int ReverseNumber(string num)
{
    string reverse_num = "";
    bool isFirstZero = true;
    for (int i = num.length()-1; i >= 0; i--)
    {
        if (num[i] == 0 && isFirstZero == true)
        {
            continue;
        }
        isFirstZero = false;
        reverse_num.push_back(num[i]);
    }  
    return stoi(reverse_num);
}
bool isPrime(int x)
{
    if (arr[x] == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    arr[0] = -1;
    arr[1] = -1;
    for (int i = 2; i <= 50000; i++)
    {
        if (arr[i] != 0)
        {
            continue;
        }
        for (int j = 2; j <= 1231123; j++)
        {            
            if (i * j > 100000)
            {
                break;
            }
            arr[i * j] = -1;
        }
    }
    
    int n;
    string num;    
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        int reverse_number = ReverseNumber(num);
        if (isPrime(reverse_number) == true)
        {
            cout << reverse_number << " ";
        }
    }

    return 0;
}