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

vector<int> v;
int main() 
{    
    clock_t start, end;
    double result;
    int i,j;
 
    for(int i=0; i<123123123; i++)
    {
        v.push_back(i);
    }
    start = clock();
    
    vector<int> v2;

    //code_start
    v2 = v;
    //code_end
    
    end = clock(); 
    result = (double)(end - start);
    printf("%f ms", result);
    return 0;
}

