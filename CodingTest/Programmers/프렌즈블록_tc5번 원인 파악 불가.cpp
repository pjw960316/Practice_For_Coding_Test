#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<string> v;
char arr[32][32];
int erase[32][32];

int test_cnt = 0;
int solution(int r, int c, vector<string> board) 
{    
    int answer = 0;
    //1. arr initialize
    for(int i=1; i<=r; i++)
    {
        for(int j=1; j<=c; j++)
        {
            arr[i][j] = board[i-1][j-1];
        }
    }
    while(1)
    {
        //2. erase 
        for(int i=1; i<=r; i++)
        {
            for(int j=1; j<=c; j++)
            {
                erase[i][j] = 0;
            }
        }
        
        //3. 조건
        for(int i=1; i<r; i++)
        {
            for(int j=1; j<c; j++)
            {
                if(arr[i][j] == arr[i+1][j] && arr[i][j] == arr[i][j+1] && arr[i][j] == arr[i+1][j+1])
                {
                    if(arr[i][j] != 'x')
                    {
                        erase[i][j] = 1;
                        erase[i+1][j] = 1;
                        erase[i][j+1] = 1;
                        erase[i+1][j+1] = 1;
                    }
                }
            }
        }
        
        //4. 역으로 이동
        int tmp = 0;
        for(int i=1; i<=r; i++)
        {
            for(int j=1; j<=c; j++)
            {
                if(erase[i][j] == 1)
                {
                    arr[i][j] = 'x';
                    tmp++;
                }
            }
        }
        cout << tmp << " ";
        //지워질 것이 없으면 종료
        if(tmp == 0)
        {
            return answer;
        }
        answer += tmp;
        
        //5. vector v에 넣기
        v.clear();
        for(int i=1; i<=c; i++)
        {
            string str = "";
            int x_cnt = 0;
            for(int j=1; j<=r; j++)
            {
                //실수 검증
                if(arr[j][i] != 'x')
                {
                    str.push_back(arr[j][i]);
                }
                else
                {
                    x_cnt++;
                }
            }
            for(int k=0; k<x_cnt; k++)
            {
                str.push_back('x');
            }
            v.push_back(str);
        }
        
        //6. arr를 vector로 채우기
        int v_x = 0;
        for(int j=1; j<=c; j++)
        {
            int v_y = 0;
            for(int i=r; i>=1; i--)
            {
                arr[i][j] = v[v_x][v_y];
                v_y++;
            }
            v_x++;
        }
    }
    return answer;
}