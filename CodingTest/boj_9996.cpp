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

using namespace std;

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	
    int tc,idx;
    string str, word;
    char next_word;
    cin >>tc;
    cin >> str;
    for(int i=0; i<str.size(); i++)
    {
        if(str[i] == '*')
        {
            next_word = str[i+1];
        }
    }
    for(int i=0; i<tc; i++)
    {
        getline(cin,word);
        idx = 0;
        int iter = 0;
        for(auto i : str)
        {
            if(i != '*')
            {
                if(iter == str.size()-1 && i == word[idx])
                {
                    cout << "DA\n";
                    break;
                }
                if(i != word[idx])
                {
                    cout << "NE\n";
                    break;
                }
                idx++;
            }
            else
            {
                while(word[idx] != next_word)
                {
                    idx++;
                }
            }     
            iter++;       
        }
    }
	return 0;
}


