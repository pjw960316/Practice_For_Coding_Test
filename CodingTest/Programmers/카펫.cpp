#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) 
{
    vector<int> answer;
    int tmp = -1;
    for(int i=1; i<=2000000; i++)
    {
        for(int j=1; j<=i; j++)
        {
            tmp = i*j;
            if(tmp > yellow)
            {
                break;
            }
            if(tmp == yellow)
            {
                if((i+2) * (j+2) - tmp == brown)
                {
                    answer.push_back(i+2);
                    answer.push_back(j+2);
                    return answer;
                }
            }
        }
    }
    return answer;
}