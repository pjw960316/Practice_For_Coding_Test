#include <string>
#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    string str = "12345";
    string tmp = str.substr(3,1);

    string str2 = "aaa";
    str2.push_back('b');
    cout << tmp; //45를 출력하고 이는 문자다.    
}