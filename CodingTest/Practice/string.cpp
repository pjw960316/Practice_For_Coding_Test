#include <string>
#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    string str = "12345";
    string tmp = str.substr(3,1);

    cout << tmp; //45를 출력하고 이는 문자다.    
}