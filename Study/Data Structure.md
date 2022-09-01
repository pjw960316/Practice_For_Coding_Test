# 목차
- [목차](#목차)
- [Unordered Map(Hash)의 Find](#unordered-maphash의-find)
    - [1. 복잡도는 상수 시간이다.](#1-복잡도는-상수-시간이다)
    - [2. key로 직접 찾으면 아래의 위험성이 발생하니 find를 사용하자.](#2-key로-직접-찾으면-아래의-위험성이-발생하니-find를-사용하자)

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
