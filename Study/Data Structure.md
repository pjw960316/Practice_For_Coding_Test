# 목차
- [목차](#목차)
- [Unordered Map(Hash)의 Find](#unordered-maphash의-find)
    - [1. 복잡도는 상수 시간이다.](#1-복잡도는-상수-시간이다)
    - [2. key로 직접 찾으면 아래의 위험성이 발생하니 find를 사용하자.](#2-key로-직접-찾으면-아래의-위험성이-발생하니-find를-사용하자)
- [Priority Queue](#priority-queue)
    - [1. 3개의 인자](#1-3개의-인자)
    - [2. Heap을 이용한 시간복잡도 (내가 이해한 것으로 정리)](#2-heap을-이용한-시간복잡도-내가-이해한-것으로-정리)
    - [3. 추가 사항](#3-추가-사항)

# Unordered Map(Hash)의 Find
### 1. 복잡도는 상수 시간이다.
- 이전에 공부했지만 모호한 부분이 있어서 정리한다.
- Find() 함수가 O(1)이고 이전에 작성한 로직
- 이전 로직
  - ![image](https://user-images.githubusercontent.com/55792986/187898039-f773c236-2a39-44f2-80ad-bfdef0d656e8.png)
- Reference
  - ![image](https://user-images.githubusercontent.com/55792986/187898202-b5550d17-4218-42c3-ab21-28e041bd2dc4.png)
  - ![image](https://user-images.githubusercontent.com/55792986/187898248-5efb5cab-9dcf-4087-b37e-486c1bd4940e.png)
### 2. key로 직접 찾으면 아래의 위험성이 발생하니 find를 사용하자.
~~~c++
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
~~~
- **Key가 존재하든 말든 m[key]로 검색을 할 때 오류는 나지 않고 return 을 한다.**
- 없는 key에 대해서 m[key]를 하면 0(항상 0인지는 모르겠다. 아마 type에 맞추지 않을까)을 value로 하여 원소로 자동으로 추가한다.
  - 그래서 위의 예제를 보면 m["ddd"]를 출력할 때 자동으로 원소를 추가시켜 4개의 원소가 m에 저장된다.
- 가장 안전한 것은 **find를 사용**하는 것 이라고 생각한다. 

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
