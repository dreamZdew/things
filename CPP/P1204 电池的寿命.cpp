#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int n;
    while (cin >> n)
    {
        int a[n];
        double sum = 0.0;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            sum += a[i];
        }
        sort(a, a + n - 1);
        sum -= a[n - 1];
        if (a[n - 1] < sum)
            printf("%.1f\n", (a[n - 1] + sum) / n);
        else
            printf("%.1f\n", sum);
    }
}