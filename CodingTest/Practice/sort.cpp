#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>

using ll = long long;
using namespace std;

vector<string> v;

//문자열 길이 대로 오름차순으로 나열하고 싶다!
bool compareBad(string a , string b)
{
    // a보다 b가 길면 b를 오른쪽에 놓아야겠다.
    if(a.length() < b.length())
    {
        return a.length() < b.length();
    }
    // a가 b보다 길면 a를 왼쪽에 놓아야겠다.
    else
    {
        return a.length() >= b.length();
    }
    // 하지만 결과는 제대로 나오지 않는다.
}

bool compareGood(string a , string b)
{
    // a와 b의 길이에 대해서 오름차순으로 정렬하겠다는 의미.
    return a.length() < b.length(); 
}

int main()
{
    v.push_back("apple");
    v.push_back("ant");
    v.push_back("sand");
    v.push_back("apple");
    v.push_back("append");
    v.push_back("sand");
    v.push_back("sand");

    //1. 잘못된 정렬
    sort(v.begin(), v.end() , compareBad);
    for(auto i : v)
    {
        cout << i << " "; //sand sand append apple sand ant apple 결과가 올바르지 않음
    }

    //2. 올바른 정렬
    sort(v.begin(), v.end() , compareGood);
    for(auto i : v)
    {
        cout << i << " "; //ant sand sand sand apple apple append 
    }
}