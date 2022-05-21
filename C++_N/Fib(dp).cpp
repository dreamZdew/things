#include <iostream>
using namespace std;
unsigned long long dp[1000];
unsigned long long Fib(int n)
{
    dp[1] = 1;
    dp[2] = 1;
    for (int i = 3; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}
int main(int argc, char const *argv[])
{
    for (int i = 1; i < 100; i++)
    {
        cout << Fib(i) << endl;
    }

    return 0;
}
