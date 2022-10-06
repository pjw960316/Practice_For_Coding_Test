#include <string>
#include <vector>
#include <iostream>

using namespace std;

struct str
{
    int x1;
    int x2;
    int y1;
    int y2;
};

int solution(string dirs) 
{
    //처음에는 set을 사용하려 했으나 set을 쓰면 operator를 구현해야 된다.
    //100% 코테에서 실수하니까 그냥 vector 이용.
    vector<str> v;
    
    int answer = 0;
    int cur_x = 0 , cur_y = 0;
    for(auto i : dirs)
    {
        //1. tmp 값 이동
        int tmp_x = cur_x;
        int tmp_y = cur_y;
        if(i== 'L')
        {
            tmp_x--;
        }
        else if(i == 'R')
        {
            tmp_x++;
        }
        else if(i == 'U')
        {
            tmp_y++;
        }
        else
        {
            tmp_y--;
        }
        
        //2. 범위
        if(-5 <= tmp_x && tmp_x <= 5 && -5 <= tmp_y && tmp_y <=5)
        {
            bool is_out = false;
            for(auto j : v)
            {
                if(j.x1 == tmp_x && j.x2 == cur_x && j.y1 == tmp_y && j.y2 ==cur_y)
                {
                    is_out = true;
                    break;
                }
            }
            if(is_out == false)
            {
                v.push_back({tmp_x , cur_x , tmp_y , cur_y});
                v.push_back({cur_x , tmp_x , cur_y , tmp_y});
            }
            cur_x = tmp_x;
            cur_y = tmp_y;
        }
    }
    answer = v.size() / 2;
    return answer;
}