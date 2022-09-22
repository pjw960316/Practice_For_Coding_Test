# 목차
- [목차](#목차)
- [개요](#개요)
- [배열의 기본방향](#배열의-기본방향)
- [전역 배열](#전역-배열)
- [Vector에서 특정 값을 가진 원소를 지우는 방식](#vector에서-특정-값을-가진-원소를-지우는-방식)
- [단계로 나누어서 설계 하는 방식](#단계로-나누어서-설계-하는-방식)
- [min, max의 함정](#min-max의-함정)
- [clear](#clear)
- [Vector를 인자로 넘길 때](#vector를-인자로-넘길-때)
- [include <bits/stdc++.h>는 뭘까?](#include-bitsstdch는-뭘까)
- [증감 연산자](#증감-연산자)
    - [1. 전위연산, 후위연산](#1-전위연산-후위연산)
    - [2. char에서의 증감](#2-char에서의-증감)

# 개요
- 독립적으로 문서를 만들기 어려운 내용은 이 곳에 정리한다.


# 배열의 기본방향
- 몇 년 동안 배열의 첫 행은 위에 생성되고, 아래로 증가시키는 모양으로 생각해왔다.
  - arr[0][2] 밑에 arr[1][2]가 존재한다.
- 문제에서는 이를 혼란시키기 위해 회전시켜서 출제하는 경우가 있다.
- 그럼에도 불구하고 **언제나 배열은 기본방향으로 변경시켜 푼다.** 그래야 헷갈리지 않는다.

# 전역 배열
- 전역 배열은 0으로 초기화 된다.
- 오랜만에 코딩테스트를 풀다 보면 가끔 의심이 든다.
  


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

# include <bits/stdc++.h>는 뭘까?
- ![image](https://user-images.githubusercontent.com/55792986/191496243-7f3100b1-edda-475c-b7b1-cbcf1afc74fb.png)

# 증감 연산자
### 1. 전위연산, 후위연산
- 일단 두 개념은 헷갈리기 때문에 쓰지 않는 것이 좋다고 생각한다.
- ![image](https://user-images.githubusercontent.com/55792986/191745888-3b3920e8-2c74-4c2a-9aba-9139914d0e89.png)
~~~c++
int i=10 , j=10;
cout << ++i << "\n"; // 11
cout << j++ << "\n"; // 10 
~~~

### 2. char에서의 증감
~~~c++
char alphabet = 'a';
cout << ++alphabet << "\n"; //'b'

alphabet = 'a';
cout << alphabet + 0x01 << "\n"; //98
printf("%c" , alphabet + 0x01); //'b'
printf("%c" , alphabet + 1); //'b'
~~~
  - **증감연산자와 함께 쓰면 간단하게 증감을 나타낼 수 있다.**
  - ASCII는 8비트의 char 값을 문자로 나타내는 것 이다.
  - 'a'의 아스키 값은 0x61 (십진수로 97)이다. 여기에 0x01을 더하면 0x62 (십진수로 98)이 된다.
    - cout으로 ASCII를 출력시키면 그것의 십진수를 출력한다.


