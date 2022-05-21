#include <iostream>
#include <algorithm>
using namespace std;
struct game
{
    int time;
    int money;
    bool played = false;
};
bool cmp(game A, game B)
{
    return A.money > B.money;
}
int main(int argc, char const *argv[])
{
    long long m;
    while (cin >> m)
    {
        int zone[600] = {0};
        game G[600];
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> G[i].time;
        for (int i = 0; i < n; i++)
            cin >> G[i].money;
        sort(G, G + n, cmp);
        for (int i = 0; i < n; i++)
        {
            for (int j = G[i].time; j >= 1; j--)
                if (zone[j] == 0)
                {
                    zone[j] = 1;
                    G[i].played = true;
                    break;
                }
        }
        for (int i = 0; i < n; i++)
            if (G[i].played == false)
                m -= G[i].money;
        cout << m << endl;
    }

    return 0;
}
