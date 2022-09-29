#include <iostream>

using namespace std;

int solution(int n, int a, int b)
{
    //answer == round
    int answer = 1;
    
    //언제나 정답은 발생하는 것이 문제에 조건으로 있으므로 무한루프는 발생하지 않는다.
    while(1)
    {
        //정답 조건
        if(a % 2 == 0 && a-1 == b)
        {
            return answer;
        }
        if(b % 2 == 0 && b-1 == a)
        {
            return answer;
        }

        if(a%2 == 0)
        {
            a /= 2;
        }
        else
        {
            a = (a+1) / 2;
        }

        if(b%2 == 0)
        {
            b /= 2;
        }
        else
        {
            b = (b+1) / 2;
        }

        answer++;
    }
}