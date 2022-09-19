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