# 목차
- [목차](#목차)
- [문자열 구분하기](#문자열-구분하기)
- [배열의 기본방향](#배열의-기본방향)
- [역순으로 벡터 정렬하기](#역순으로-벡터-정렬하기)
- [Vector에서 특정 값을 가진 원소를 지우는 방식](#vector에서-특정-값을-가진-원소를-지우는-방식)
- [단계로 나누어서 설계 하는 방식](#단계로-나누어서-설계-하는-방식)
- [min, max의 함정](#min-max의-함정)
- [Associative Container의 Erase](#associative-container의-erase)
- [Associative Container의 역순 순회](#associative-container의-역순-순회)
    - [1. Library](#1-library)
    - [2. Associative Container의 Iterator 분석](#2-associative-container의-iterator-분석)
- [clear](#clear)
- [Vector를 인자로 넘길 때](#vector를-인자로-넘길-때)


# 문자열 구분하기
- ![image](https://user-images.githubusercontent.com/55792986/181409938-38251069-1d93-4f6b-83f2-8d2e2ce63d8f.png)
- 참 여럽다... C++에서의 문자열은

# 배열의 기본방향
- 몇 년 동안 배열의 첫 행은 위에 생성되고, 아래로 증가시키는 모양으로 생각해왔다.
  - arr[0][2] 밑에 arr[1][2]가 존재한다.
- 문제에서는 이를 혼란시키기 위해 회전시켜서 출제하는 경우가 있다.
- 그럼에도 불구하고 **언제나 배열은 기본방향으로 변경시켜 푼다.** 그래야 헷갈리지 않는다.
  
# 역순으로 벡터 정렬하기
- 라이브러리를 암기할 필요가 없지만 이를 요구하는 시험들이 있다.
- 정렬된 벡터에 대해서 reverse(v.begin() , v.end()) 를 진행하자.
  - sort(v.begin() , v.end() , greater<int>()) 도 있다.

# Vector에서 특정 값을 가진 원소를 지우는 방식
1. **Vector의 원소를 map의 키로 저장하고, value를 bool이나 int로 저장하기**
     - 원소의 삽입 및 삭제가 매우 간편해지고 정렬도 되어 진다.
     - vector의 3이라면 map에서는 (3,true)
     - vector와 map의 장점을 얼마나 쉽게 마이그레이션 할 수 있는지가 코테에서 중요하다.

2. **정렬 되지 않은 순서가 중요한 경우 vector의 erase를 이용한다.**
     - ![image](https://user-images.githubusercontent.com/55792986/181666647-80d7c0b6-9639-4957-af98-0cf447058f3b.png)

# 단계로 나누어서 설계 하는 방식
- 보통 종이에서 알고리즘을 설계할 때는 문제를 단계를 나누어 해결한다. 코드에서도 마찬가지로 주석을 이용하여 단계를 나눈다.
  - ![image](https://user-images.githubusercontent.com/55792986/181708250-1c198d3f-71c5-4528-b15d-624efb32fb73.png)
  - 이렇게 단계를 나누면 디버깅 및 테스트하기가 쉬워진다. 
    - 단계 마다 로그를 찍어보면 어떤 단계에서 에러가 시작되었는지 쉽게 파악할 수 있다.

# min, max의 함정
- ![20220729_170104](https://user-images.githubusercontent.com/55792986/181713182-2d53fcd9-e692-48f6-a4c6-8eb84d6da17d.png)
  - 비교하는 타입이 달라서 에러가 난다.
- ![image](https://user-images.githubusercontent.com/55792986/181713297-fe081fe4-282e-42ff-99b9-cf14ae6fae54.png)
  - 이렇게 하면 된다.

# Associative Container의 Erase
- **Set, Map의 erase는 iterator와 key를 이용하여 모두 지울 수 있다.**
- key의 경우 값이므로 해당 값을 erase의 인자로 넣어 지운다.
~~~c++
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
~~~
- iterator 순회를 이용해서 제거한다.
- **iterator는 주소이므로 지워버리면 해당 메모리가 해제 된다. 그러므로 반복문에서 널 포인터에 i++를 하므로 에러가 난다. 반드시 i에 다른 iterator 값을 저장해준다.**

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

# clear
- 자료구조에 저장된 값 들을 0으로 만드는 것이 아니라 자료구조의 모든 원소를 제거하는 메서드.

# Vector를 인자로 넘길 때
~~~c++
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>

using ll = long long;
using namespace std;

int callByValue(vector<int> v)
{
    printf("cbv : %p\n" ,v); //0061FF00 (다름)
    v[3] = 77;
}

int callByRefer(vector<int> &v)
{
    printf("cbr : %p\n" ,v); // 0061FEF0
    v[2] = 88;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> v;
    for(int i=0; i<5; i++)
    {
        v.push_back(i*10);
    }

    printf("local : %p\n" ,v); //0061FEF0

    callByValue(v);
    callByRefer(v);

    for(auto i : v)
    {
        cout << i << " "; //0 10 88 30 40
    }
   return 0;
}
~~~
- callByValue는 vector의 값을 **복사해서** 전달하기 때문에 새로운 벡터가 생성되는 것과 같다.
- callByRefer는 vector의 주소를 전달하기 때문에 main에서 선언한 vector와 동일하다. 
  - 매개변수에서 주소 값을 받아야 한다.
- 알고리즘의 경우 전역변수를 이용하면 참조할 대상을 전역에 놓기 때문에 매개변수가 필요 없어서 지금까지 전역변수로 이용했다. 하지만 지역변수로 전달해야 하는 문제도 종종 있었기에 한 번 정리했다.
  - call-by-value는 복사하기 때문에 오버헤드가 클 것으로 예상된다.
  - call-by-reference도 언제나 포인터 만큼의 매개변수 메모리를 할당하긴 한다.

