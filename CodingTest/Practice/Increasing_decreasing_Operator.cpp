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

    //1. front-back
    int i=10 , j=10;
    cout << ++i << "\n"; // 11
    cout << j++ << "\n"; // 10 

    //2. char
    char alphabet = 'a';
    cout << ++alphabet << "\n"; //'b'
    alphabet = 'a';
    cout << alphabet + 0x01 << "\n"; //98
    printf("%c" , alphabet + 0x01); //'b'
    printf("%c" , alphabet + 1); //'b'

	return 0;
}