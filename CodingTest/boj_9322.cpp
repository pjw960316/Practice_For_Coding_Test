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

string arr1[1001];
string arr2[1001];
string arr3[1001];
string arr4[1001];
vector<pair<int,int>> v;

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);

    int tc,word_cnt;
    cin >> tc;
    for(int i=0; i<tc; i++)
    {
        cin >> word_cnt;
        for(int i=0; i<word_cnt; i++)
        {
            cin >> arr1[i];
        }
        for(int i=0; i<word_cnt; i++)
        {
            cin >> arr2[i];
        }
        for(int i=0; i<word_cnt; i++)
        {
            for(int j=0; j<word_cnt; j++)
            {
                if(arr1[i] == arr2[j])
                {
                    v.push_back({j,i});
                }
            }
        }
        for(int i=0; i<word_cnt; i++)
        {
            cin >> arr3[i];
        }
        for(unsigned int i=0; i<v.size(); i++)
        {
            arr4[v[i].second] = arr3[v[i].first];
        }
        for(int i=0; i<word_cnt; i++)
        {
            cout << arr4[i] << " ";
        }
        cout << "\n";
        v.clear();
    }
	return 0;
}


