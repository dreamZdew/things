#include <iostream>
using namespace std;
int n, m, x;
int a[100000];
int find(int target)
{
    int l = 0, h = n - 1;
    if (target < a[l])
        return -1;
    if (target > a[h])
        return a[h];
    while (l < h)
    {
        int mid = (l + h) / 2;
        if (target < a[mid])
        {
            h = mid;
        }
        else
            l = mid + 1;
    }
    while (l >= 0)
    {
        if (a[l] <= target)
            return a[l];
        l--;
    }
}
int main()
{
    cin >> n >> m;

    for (int i = 0; i < n; i++)
        cin >> a[i];
    while (m--)
    {
        cin >> x;
        cout << find(x) << endl;
    }
}