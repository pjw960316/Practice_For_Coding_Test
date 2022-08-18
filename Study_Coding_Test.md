# 목차
- [목차](#목차)
- [문자열 구분하기](#문자열-구분하기)
- 


# 문자열 구분하기
- ![image](https://user-images.githubusercontent.com/55792986/181409938-38251069-1d93-4f6b-83f2-8d2e2ce63d8f.png)
- 참 여럽다... C++에서의 문자열은

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
~~~
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


