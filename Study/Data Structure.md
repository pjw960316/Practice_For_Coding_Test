# 목차
- [목차](#목차)
- [Priority Queue](#priority-queue)
    - [1. 3개의 인자](#1-3개의-인자)
    - [2. Heap을 이용한 시간복잡도 (내가 이해한 것으로 정리)](#2-heap을-이용한-시간복잡도-내가-이해한-것으로-정리)
    - [3. 추가 사항](#3-추가-사항)
- [Set 과 Vector에 구조체를 넣어보자](#set-과-vector에-구조체를-넣어보자)
    - [1. 문제 코드 : set에 구조체를 넣는 경우](#1-문제-코드--set에-구조체를-넣는-경우)
    - [2. 해결 방법](#2-해결-방법)
- [Deque](#deque)


# Priority Queue
### 1. 3개의 인자
- ![20220919_163918](https://user-images.githubusercontent.com/55792986/190970634-22ddbf4c-b10f-4dad-9963-54694aa11d5e.png)
  - container는 반드시 vector, list, deque을 이용한다.
~~~c++
#include <iostream>
#include <queue>
using namespace std;

int main()
{
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({30,1});
    pq.push({20,2});
    pq.push({10,-1});

    auto tmp = pq.top();
    cout << tmp.first << " " << tmp.second << "\n"; // 10 -1
    //오름차순 힙으로 정렬되어 있다. 그러므로 10 -1이 가장 먼저 나온다.
}
~~~
### 2. Heap을 이용한 시간복잡도 (내가 이해한 것으로 정리)
- Max Heap or Min Heap일 테니 가장 큰 값이나 작은 값을 찾을 때는 O(1)이다.
  - Root 니까
- Insert, Erase 과정도 부모나 자식과 순차적으로 비교하기 때문에 트리의 깊이가 된다.
  - 트리의 깊이는 log(n)

### 3. 추가 사항
- 기존의 queue와는 다르게 front()와 back()을 이용하지 않고 top()만을 이용한다.
- 원하는 순서대로 정렬하고 이 순서로 출력할 수 있는 매우 훌륭한 자료구조다.
- greater는 오름차순, less는 내림차순이다.
- **greater 나 less는 사용하는 컨테이너의 첫 번째 원소의 값으로 비교한다.**

# Set 과 Vector에 구조체를 넣어보자
### 1. 문제 코드 : set에 구조체를 넣는 경우
~~~c++
struct str
{
    int a;
    int b;
    string c;
};

set<str> s;
vector<str> v;

set<pair<int,int>> s_pair;
vector<pair<int,int>> v_pair;

int main()
{
    //1. struct test
    v.push_back({3,2,"bca"});
    v.push_back({2,25,"aaa"});
    v.push_back({4,1,"ewerwer"});

    ** 에러가 발생한다! **
    //s.insert({3,2,"bca"});
    //s.insert({2,25,"aaa"});
    //s.insert({4,1,"ewerwer"});

    for(auto i : v)
    {
        cout << i.a << " " << i.b << " " << i.c << "\n";
    }
    /* 올바른 출력
    3 2 bca
    2 25 aaa
    4 1 ewerwer
    */

    //2. pair
    v_pair.push_back({3,2});
    v_pair.push_back({2,4});
    v_pair.push_back({4,-1});

    s_pair.insert({3,2});
    s_pair.insert({2,4});
    s_pair.insert({4,-1});

    for(auto i : v_pair)
    {
        cout << i.first << " " << i.second << "\n";
    }
    /* 올바른 출력
    3 2
    2 4
    4 -1
    */

    for(auto i : s_pair)
    {
        cout << i.first << " " << i.second << "\n";
    }
    /* 올바른 출력
    2 4
    3 2
    4 -1
    */
	return 0;
}
~~~
- pair의 경우 다음 자료구조들에서는 모두 안전하게 출력이 된다.
- **Set과 map에서 구조체를 타입으로 하는 경우 에러가 발생**한다.
  
### 2. 해결 방법
- 문제 상황
  - ![image](https://user-images.githubusercontent.com/55792986/194299728-c37a3adf-5246-42a6-a3ae-840ca35b4752.png)
- 해결 방법
  - ![image](https://user-images.githubusercontent.com/55792986/194299959-6168a600-ff63-4887-b729-d1ba16cff6b2.png)
  - 구조체를 만들 때 operator를 반드시 구현해야 한다.
- 다른 자료
  - ![image](https://user-images.githubusercontent.com/55792986/194300280-50ebb8d0-60e5-4021-8db9-831b8888a0fb.png)
- 결론
  - operator를 추가하는 것은 절대 코딩테스트에서 기억하지 못한다.
  - 그러므로 Vector를 이용한다.
  - Vector를 이용해서 해결하는 방식이 복잡도가 오버되면 다른 알고리즘으로 구현한다. 


# Deque
- [Reference](https://blockdmask.tistory.com/73)
- queue나 stack은 순회가 불가능 하기 때문에 순회가 필요한 경우 Deque으로 대체해서 푼다.