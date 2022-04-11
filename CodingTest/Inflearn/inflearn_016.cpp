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

map<char, int> m1, m2;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for (char word = 'a'; word < 'z'; word++)
    {
        m1.insert({ word,0 });
        m2.insert({ word,0 });
    }
    for (char word = 'A'; word < 'Z'; word++)
    {
        m1.insert({ word,0 });
        m2.insert({ word,0 });
    }
    string str1, str2;
    cin >> str1 >> str2;
    for (auto i : str1)
    {
        m1[i]++;
    }
    for (auto i : str2)
    {
        m2[i]++;
    }
 
    for (char word = 'a'; word < 'z'; word++)
    {
        if (m1[word] != m2[word])
        {
            cout << "NO";
            return 0;
        }
    }
    for (char word = 'A'; word < 'Z'; word++)
    {
        if (m1[word] != m2[word])
        {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
    return 0;
    
    return 0;
}