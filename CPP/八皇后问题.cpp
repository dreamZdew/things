#include <iostream>
using namespace std;
const int N = 20;
int q[N];
int count = 0;
void display(int n)
{
    count++;
    for (int i = 1; i <= n; i++)
        cout << "(" << i << "," << q[i] << ") ";
    cout << endl;
}
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
        display(n);
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
    queen(1, 6);
    cout<<count<<endl;
}
