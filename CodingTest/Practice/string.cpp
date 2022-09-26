#include <string>
#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    string sstr = "abcde";
    sstr.insert(3, "ffff"); // index 3에 문자열을 추가한다.
    cout << sstr << "\n";  

    sstr.erase(4,1); // 1개를 지운다.
    cout << sstr << "\n";
}