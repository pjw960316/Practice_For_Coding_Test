# 목차
- [목차](#목차)
- [개요](#개요)
- [배열의 기본방향](#배열의-기본방향)
- [전역 배열](#전역-배열)
- [min, max의 함정](#min-max의-함정)
- [단계로 나누어서 설계 하는 방식](#단계로-나누어서-설계-하는-방식)
- [include <bits/stdc++.h>는 뭘까?](#include-bitsstdch는-뭘까)
- [증감 연산자](#증감-연산자)
    - [1. 전위연산, 후위연산](#1-전위연산-후위연산)
    - [2. char에서의 증감](#2-char에서의-증감)
- [Windows의 EOF (End Of File)](#windows의-eof-end-of-file)
- [너무 큰 수에 대한 % 연산 문제](#너무-큰-수에-대한--연산-문제)

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

# min, max의 함정
- ![20220729_170104](https://user-images.githubusercontent.com/55792986/181713182-2d53fcd9-e692-48f6-a4c6-8eb84d6da17d.png)
  - 비교하는 타입이 달라서 에러가 난다.
- ![image](https://user-images.githubusercontent.com/55792986/181713297-fe081fe4-282e-42ff-99b9-cf14ae6fae54.png)
  - 이렇게 하면 된다.

# 단계로 나누어서 설계 하는 방식
- 보통 종이에서 알고리즘을 설계할 때는 문제를 단계를 나누어 해결한다. 코드에서도 마찬가지로 주석을 이용하여 단계를 나눈다.
  - ![image](https://user-images.githubusercontent.com/55792986/181708250-1c198d3f-71c5-4528-b15d-624efb32fb73.png)
  - 이렇게 단계를 나누면 디버깅 및 테스트하기가 쉬워진다. 
    - 단계 마다 로그를 찍어보면 어떤 단계에서 에러가 시작되었는지 쉽게 파악할 수 있다.


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

~~~c++
char alphabet = 'A';
alphabet += 0x20;
cout << alphabet; //A
~~~
  - 느낌상 소문자의 아스키 코드가 대문자의 아스키 코드 보다 작을 것이라 예상했다.
  - 하지만 대문자의 아스키 코드가 소문자의 아스키 코드보다 작다.
  - 소문자 <-> 대문자는 대문자에 0x20을 더하면 된다.
  
# Windows의 EOF (End Of File)
- Ctrl + Z를 눌러서 직접 입력해준다.

# 너무 큰 수에 대한 % 연산 문제
[Programmers](https://school.programmers.co.kr/learn/courses/30/lessons/12914)
  - long long은 2^63이므로 4*10^16 정도 되므로 문제에서 오버플로우가 일어날 것이라고 전혀 생각하지 못했다.
  - **% 연산으로 출력하는 문제는 코딩 중간 중간에서 나머지 연산을 진행한다.**
  - 다시 말해 **항상 예상 보다 큰 수 (심지어 long long 보다도 큰 수)가 계산 과정에서 나타나 오버플로우가 발생 할 수 있다고 염두하고 문제를 푼다.**


