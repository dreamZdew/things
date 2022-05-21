#include <iostream>
#include <string>
using namespace std;
int dp[100][100];

string LCS(string a, string b) //求解a和b的最长子序列
{
    string z;
    for (int i = 0; i <= a.length(); i++)
    {
        for (int j = 0; j <= b.length(); j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else if (a[i - 1] == b[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    int k = dp[a.length()][b.length()];
    int i = a.length(), j = b.length();
    while (k > 0)
    {
        if (dp[i][j] == dp[i - 1][j])
            i--;
        else if (dp[i][j] == dp[i][j - 1])
            j--;
        else
        {
            z += a[i - 1];
            i--;
            j--;
            k--;
        }
    }
    return z;
}

int main(int argc, char const *argv[])
{
    string a, b;
    cin >> a >> b;
    cout << LCS(a, b);
    

    return 0;
}
