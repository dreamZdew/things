#include <iostream>
#include <cmath>
using namespace std;
long long n;
long long a[100000];
long long ask;
long long m;

int getMinNum(long long a, long long b, long long c)
{
    return (a > b ? (b > c ? c : b) : (a > c ? c : a));
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cin >> m;
    while (m--)
    {
        cin >> ask;
        int low = 0, mid = n / 2, high = n - 1;
        while (low < high)
        {
            if (a[mid] < ask)
            {
                low = mid + 1;
                mid = (high + low + 1) / 2;
            }
            else
            {
                high = mid;
                mid = (high + low) / 2;
            }
        }
        long long t1 = 100000000000, t2 = 100000000000, t3 = 100000000000;
        if (mid > 0)
            t1 = ask - a[mid - 1];
        t2 = abs(ask - a[mid]);
        if (a[mid + 1] > 0)
            t3 = a[mid + 1] - ask;
        if (getMinNum(t1, t2, t3) == t1)
            cout << a[mid - 1] << endl;
        else if (getMinNum(t1, t2, t3) == t2)
            cout << a[mid] << endl;
        else if (getMinNum(t1, t2, t3) == t3)
            cout << a[mid + 1] << endl;
    }
}