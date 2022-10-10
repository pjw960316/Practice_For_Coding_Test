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

map<int,int> m;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //1. 선언한 map의 크기
    cout << m.size() << "\n"; // 0

    //2. insert의 크기
    m.insert({1,1});
    cout << m.size() << "\n"; // 1

    //3. []으로 선언할 때
    cout << m[2] << "\n"; // m[2]를 출력시키게 하면 0을 자동으로 넣는다. (int의 default value = 0)
    cout << m.size() << "\n"; // 2

    m[3] = 1;
    cout << m.size() << "\n"; // 3

    //4. string의 default value
    map<int, string> m_string;
    cout << m_string[1]; 
    if(m_string[1] == "")
    {
        cout << "YES"; //YES를 출력한다. 그러므로 string 의 default value는 ""이다.
    }


    return 0;
}