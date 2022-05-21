#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int d[n]; // dpc[i]=max( dpc[i-1]+arr[i], arr[i])
    d[0] = a[0];
    for (int i = 1; i < n; i++)
    {
        if (d[i - 1] + a[i] > a[i])
            d[i] = d[i - 1] + a[i];
        else
            d[i] = a[i];
    }
    int max = d[0];
    for (int i = 0; i < n; i++)
    {
        if (d[i] > max)
            max = d[i];
    }
    cout << max << endl;
}