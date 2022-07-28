#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main()
{
    stringstream ss;
    string test = "abc def ghi";
    ss.str(test);

    string n;
    while(ss >> n)
    {
        cout << n << endl;
    }
}