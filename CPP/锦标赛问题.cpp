#include <iostream>
#include <iomanip>
using namespace std;
const int n = 16;
int cal[20][20] = {0};
void method(int k)
{
    if (k == 1)
    {
        cal[1][1] = 1;
        cal[2][2] = 1;
        cal[2][1] = 2;
        cal[1][2] = 2;
    }
    else
    {

        method(k / 2);

        for (int i = k / 2 + 1; i <= k; i++)
            for (int j = 1; j <= k / 2; j++)
                cal[i][j] = cal[i - k / 2][j] + k / 2;

        for (int i = 1; i <= k / 2; i++)
            for (int j = k / 2 + 1; j <= k; j++)
                cal[i][j] = cal[i + k / 2][(j + k / 2) % k];

        for (int i = k / 2 + 1; i <= k; i++)
            for (int j = k / 2 + 1; j <= k; j++)
                cal[i][j] = cal[i - k / 2][j - k / 2];
    }
}

int main(int argc, char const *argv[])
{
    method(n);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            cout << setw(2) << cal[i][j] << " ";
        cout << endl;
    }

    return 0;
}
