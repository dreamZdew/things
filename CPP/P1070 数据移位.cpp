#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
    int n;
    while (cin >> n)
    {
        int a[100], t[100];
        int k;
        cin >> k;
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < k; i++)
        {
            t[i] = a[i];
        }

        for (int i = k, j = 0; i < n; i++, j++)
        {
            a[j] = a[i];
        }

        for (int i = n - k, j = 0; i < n; i++, j++)
        {
            a[i] = t[j];
        }
        for (int i = 0; i < n; i++)
        {
            cout << a[i]<<endl;
        }
    }

    return 0;
}
