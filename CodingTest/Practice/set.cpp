#include <set>
#include <iostream>

using namespace std;


int main()
{
    set<int> s;
    for(int i=1; i<10; i++)
    {
        s.insert(i*10);
    }

    int cnt = 0;
    for(auto i = s.begin(); i != s.end(); i++)
    {
        cnt++;
        auto tmp = i++;
        if(cnt == 3)
        {
            s.erase(i);
        }
        i = tmp;
    }

    for(auto i : s)
    {
        cout << i << " ";
    }
}