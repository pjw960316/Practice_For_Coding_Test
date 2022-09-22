# 목차
- [목차](#목차)
- [Associative Container의 역순 순회](#associative-container의-역순-순회)
    - [1. Library](#1-library)
    - [2. Associative Container의 Iterator 분석](#2-associative-container의-iterator-분석)
- [Associative Container의 Erase](#associative-container의-erase)

# Associative Container의 역순 순회
### 1. Library
- 정방 순회를 이용한 후 stack, vector로 가공해서 하는 방법도 있다. 하지만 매우 간단한 걸 library에서 제공한다.
~~~c++
for(auto iter = m.rbegin(); iter != m.rend(); iter++)
    {
        auto tmp = *iter;
        for(auto i : tmp.second)
        {
            answer.push_back(i);
        }
    }
~~~
  - 기존의 방식에서 begin() -> rbegin() , end() -> rend()를 이용하면 된다.
  - m.end() 자체가 자료구조의 맨 끝을 가리키는 포인터가 아니므로 위의 방식을 사용해야 한다.

### 2. Associative Container의 Iterator 분석
~~~c++
map<int,int> m;
    for(int i=0; i<3; i++)
    {
        m.insert({i*10 , i*11});
    }

    auto iter = m.begin(); //auto를 컴파일러가 판별하도록 제시.

    //1. 일반적인 map 순회
    for(iter = m.begin(); iter != m.end(); ++iter)
    {
        printf("%p " , iter);
    }
    // 결과 : 006C1BA8 006C1BD8 006C1BF8 
    printf("\n\n");
 
    //2. map의 begin() 부터 증가해보기
    iter = m.begin();
    printf("%p\n" , iter);
    printf("%p\n" , ++iter);
    printf("%p\n" , ++iter);
    printf("%p\n" , ++iter);
    /* 결과
    006C1BA8
    006C1BD8
    006C1BF8
    0061FEDC
    */

    printf("\n\n");

    //3. map의 end() 부터 증가해보기
    iter = m.end();
    printf("%p\n" , iter);
    printf("%p\n" , --iter);
    printf("%p\n" , --iter);
    printf("%p\n" , --iter);

    /* 결과
    0061FEDC
    006C1BF8
    006C1BD8  
    006C1BA8
    */
    printf("\n\n");

    //4. map의 begin() 부터 감소해보기
    iter = m.begin();
    printf("%p\n" , iter);
    printf("%p\n" , --iter);
    printf("%p\n" , --iter);
    printf("%p\n" , --iter);

    /* 결과
    006C1BA8
    0061FEDC
    006C1BF8
    006C1BD8
    */

    printf("\n\n");

    //5. map의 end() 부터 증가해보기
    iter = m.end();
    printf("%p\n" , iter);
    printf("%p\n" , ++iter);
    printf("%p\n" , ++iter);
    printf("%p\n" , ++iter);  

    /* 결과
    0061FEDC
    006C1BF8
    0061FEDC
    006C1BF8
    */

    printf("\n\n");

    //6. 위의 결론을 통해 map을 역순으로 순회 하는 방법
    for(auto iter = --m.end(); iter != --m.begin(); --iter)
    {
        cout << (*iter).first << " " << (*iter).second << "\n";
    }
    /* 결과
    20 22
    10 11
    0 0
    */
~~~
  - map의 begin ~ 실제 마지막 원소까지는 일정한 바이트 만큼의 차이를 두고 연속적으로 저장된다.
  - map의 end만은 관련 없는 주소값으로 저장된다.
  - **그러나 map의 실제 마지막 원소에서 증가를 시키면 map의 end 주소로 이동한다.**
    - 그렇기 때문에 이를 생각하면 iterator를 이용해서 역순으로 출력하는 것은 어렵지 않다.
  - 4번 5번의 결과를 보면 begin에서 감소시키고, end에서 증가시키면 신기하게 다시 map의 iterator들을 참고하지만 이는 무시하자.
  - **우리가 기억해야 할 것은 map의 begin은 map에서 실제로 이용되는 값의 주소를 가리키므로 연속적인 주소의 첫 주소다. 하지만 map의 end는 map에서 실제로 이용되는 값의 주소가 아니라 map이 특이하게 저장하는 end flag의 주소다. 그러나 map의 실제마지막 값의 주소에서 iterator를 증가시키면 map의 end flag의 주소로 이동한다!**

# Associative Container의 Erase
- **Set, Map의 erase는 iterator와 key를 이용하여 모두 지울 수 있다.**
- key의 경우 값이므로 해당 값을 erase의 인자로 넣어 지운다.
- iterator로 지우는 방법은 실수 할 여지가 크다.
~~~c++
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
~~~
- iterator 순회를 이용해서 제거한다.
- **iterator는 주소이므로 지워버리면 해당 메모리가 해제 된다. 그러므로 반복문에서 널 포인터에 i++를 하므로 에러가 난다. 반드시 i에 다른 iterator 값을 저장해준다.**