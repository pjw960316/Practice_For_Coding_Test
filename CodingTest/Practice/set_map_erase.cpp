#include <set>
#include <map>
#include <iostream>

using namespace std;

set<int> s;
map<int,int> m;

void printSetAndMap()
{
    cout << "set : ";
    for(auto i : s)
    {
        cout << i << " ";
    }
    cout << "\nmap : ";
    for(auto i : m)
    {
        cout << i.first << " " << i.second << " / ";
    }
    cout << "\n";
}

int main()
{
    //1. set, map 선언    
    for(int i=1; i<=5; i++)
    {
        s.insert(i*10);
    }
    
    for(int i=1; i<=5; i++)
    {
        m.insert({i*2,i*10});
    }

    printSetAndMap();
    //set : 10 20 30 40 50 
    //map : 2 10 / 4 20 / 6 30 / 8 40 / 10 50

    //2. key로 지우기
    s.erase(30);
    m.erase(4);

    printSetAndMap();
    //set : 10 20 40 50 (30이 제거된다!)
    //map : 2 10 / 6 30 / 8 40 / 10 50 (key가 4인 원소가 제거된다! 4번째 원소를 제거하지 않는다.)

    
    //3. iterator로 지우기
    //2번 예제에서 지운 것들 복구
    s.insert(30);
    m.insert({4,20});

    int cnt = 0;
    for(auto i = s.begin(); i != s.end(); i++)
    {
        cnt++;
        auto tmp = i++; //아래에서 iterator i를 지워버리므로 segment fault가 일어난다. 그러므로 주소를 임시저장 한다.
        if(cnt == 3)
        {
            s.erase(i);
        }
        i = tmp;
    }

    cnt = 0;
    for(auto i = m.begin(); i != m.end(); i++)
    {
        cnt++;
        auto tmp = i++; //아래에서 iterator i를 지워버리므로 segment fault가 일어난다. 그러므로 주소를 임시저장 한다.
        if(cnt == 3)
        {
            m.erase(i);
        }
        i = tmp;
    }

    printSetAndMap();
    //set : 10 20 30 50
    //map : 2 10 / 4 20 / 6 30 / 10 50
    //iterator는 0부터이므로 3번째 인덱스의 원소를 지운다.
}