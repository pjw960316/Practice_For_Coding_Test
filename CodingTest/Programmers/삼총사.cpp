#include <string>
#include <vector>

using namespace std;

//간단한 문제는 DFS까지 가지 않는다.
int solution(vector<int> number) 
{
    int answer = 0;
    int sum = 0;
    int ssize = number.size();
    for(int i=0; i<ssize-2; i++)
    {
        for(int j=i+1; j<ssize-1; j++)
        {
            for(int k= j+1; k<ssize; k++)
            {
                sum = 0;
                sum += number[i] + number[j] + number[k];
                if(sum == 0)
                {
                    answer++;
                }
            }
        }
    }
    
    return answer;
}