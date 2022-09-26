#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int main()
{
    unordered_map<string,int> m;
    m.insert({"aaa" , 1});
    m.insert({"bbb" , 2});
    m.insert({"ccc" , 3});

    cout << m["aaa"] << "\n"; // 1
    cout << m["ddd"] << "\n"; // 0

    cout << m.size() << "\n"; // 4

    if(m.find("aaa") != m.end())
    {
        cout << "aaa find\n";
    }
    // "aaa find"를 출력한다.
    if(m.find("ddd") != m.end())
    {
        cout << "ddd find\n";
    }
    // "ddd find"를 출력한다.

    cout << m["ddd"]; // 0

   
    return 0;
}
