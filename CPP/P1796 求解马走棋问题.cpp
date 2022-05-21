#include <iostream>
using namespace std;
//马向右走指从 (X,Y) 走到 (X+2, Y+1) 或 (X+1, Y+2) 位置
int find(int x, int y)
{
    if (x <= 1 || y <= 1)
        return 0;
    if (x == 2 && y == 3)
        return 1;
    if (x == 3 && y == 2)
        return 1;
    return find(x - 1, y - 2) + find(x - 2, y - 1);
}

int main()
{
    int n, m;
    cin >> n >> m;
    cout << find(n, m) << endl;
}