#include <string>
#include <vector>
#include <map>

using namespace std;

int arr[13] = {-1,31,29,31,30,31,30,31,31,30,31,30,31};
string solution(int a, int b) 
{
    string answer = "";
    int sum = 0;
    for(int i=1; i<a; i++)
    {
        sum += arr[i];
    }
    sum += b;
    sum -= 1;
    
    map<int,string>m;
    m[0]="SUN";
    m[1]="MON";
    m[2]="TUE";
    m[3]="WED";
    m[4]="THU";
    m[5]="FRI";
    m[6]="SAT";
    
    int tmp = sum % 7;
    int ret = (5 + tmp) % 7;
    answer = m[ret];
    return answer;
}