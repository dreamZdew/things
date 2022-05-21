#include <iostream>
using namespace std;
int q[9];
int q1[9];
int ans;

bool place(int i, int j)
{
    if (i == 1)
        return true;
    for (int k = 1; k < i; k++)
        if (j == q[k] || abs(k - i) == abs(q[k] - j))
            return false;
    return true;
}
void queen(int i, int n) // n皇后问题求解
{
    if (i > n)
    {
        for (int i = 1; i <= 8; i++)
        {
            if (q1[i] != 0 && q1[i] != q[i])
                break;
            if (i == 8 && (q[8] == q1[8]||q1[8]==0))
            {
                ans++;
                break;
            }
        }
    }
    else
    {
        for (int j = 1; j <= n; j++)
            if (place(i, j))
            {
                q[i] = j;
                queen(i + 1, n);
            }
    }
}
int main()
{
    int n;
    while (cin >> n)
    {
        ans = 0;
        for (int i = 0; i < 9; i++)
        {
            q[i] = 0; q1[i] = 0;
        }
        if (n == 1)
            q1[1] = 1;
        for (int i = 2; i <= 64; i++)
        {
            cin >> n;
            if (n == 1)
                q1[i / 8 + 1] = i % 8;
        }
        queen(1, 8);
        cout << ans << endl;
    }
}
/*
1 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0
*/