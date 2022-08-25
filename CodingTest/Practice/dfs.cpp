#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

using ll = long long;
using namespace std;

string coffee[4] = {"americano", "latte", "mocha", "water"};
string arr[5]; //2번 조건 : index가 depth인 배열

//1번 조건 : 재귀 함수
void Dfs(int depth)
{
    // Depth가 오버되면 종료한다.
    if(depth == 5)
    {
        for(int i=1; i<=4; i++)
        {
            cout << arr[i] << " ";
        }
        cout << "\n";
        return;
    }

    // 현재 Depth에 원소를 넣을 때, 이전에 사용한 원소가 있는지 검사한다.
    // 이 때 visit 배열을 따로 만들 게 아니라 이미 넣고 있던 배열을 검사하면 된다.
    // Depth는 언제나 1부터 채워 나가고, 0번 depth가 root로 가상으로 존재한다고 가정한다.
    for(int i=0; i<4; i++)
    {
        bool is_visit = false;
        for(int j=0; j<depth; j++) //이전 depth에서 해당 커피를 마셨는지 검사한다.
        {
            if(arr[j] == coffee[i])
            {
                is_visit = true;
                break;
            }
        }
        if(is_visit == false)
        {
            arr[depth] = coffee[i];
            Dfs(depth+1);
        }
    }

}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Dfs(1);

   return 0;
}