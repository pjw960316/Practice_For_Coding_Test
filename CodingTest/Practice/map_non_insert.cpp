#include <map>
#include <iostream>

using namespace std;

int main()
{
    map<string,int> m;
    
    //삽입 방식_1
    m.insert({"jiwon" , 111});

    //삽입 방식_2
    m["jitwo"] = 222;

    cout << m["jiwon"] << " " << m["jitwo"] << " " <<m["jithree"]; // 111 222 0
}
