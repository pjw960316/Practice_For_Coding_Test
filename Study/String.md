# 목차
- [목차](#목차)
- [개요](#개요)
- [문자열 슬라이싱](#문자열-슬라이싱)
- [문자열 <-> 숫자](#문자열---숫자)

# 개요
- 문자열 다루는 것은 어렵지만 현업에서 가장 중요하다.
- 코딩테스트를 넘어서 개발자라면 잘 다루어야 한다.
- [Reference](https://luv-n-interest.tistory.com/1166?category=973485)

# 문자열 슬라이싱
- 이전에는 문자열 문제를 자주 풀지 않아서 push_back()이나 str[idx]를 이용해서 복잡하게 슬라이싱을 했다.
- **substr**을 이용한다.
- 문자열의 일부를 리턴하고 이는 string type이 된다.
- 문자열의 일부를 이용하는 것은 문자열의 기초다.
~~~c++
int main()
{
    string str = "12345";
    string tmp = str.substr(3,2); //3번 인덱스 부터 2개의 문자를 슬라이싱하여 문자열로 반환한다.

    cout << tmp; //45를 출력하고 이는 문자다.    
}
~~~

# 문자열 <-> 숫자
- ![image](https://user-images.githubusercontent.com/55792986/191493039-909485d0-9142-447f-b5e1-aa8757d8ffee.png)
- 숫자를 문자열로 바꾸는 것은 to_string(숫자)
