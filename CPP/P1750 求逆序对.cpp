#include <iostream>
using namespace std;
long long ans = 0;
long long arr[500000];
void Merge(long long a[], long long low, long long mid, long long high) //合并两个
{
    long long i = low, j = mid + 1, k = 0;
    long long* tmp = new long long[high - low + 1];
    while (i <= mid && j <= high)
    {
        if (a[i] > a[j])
        {
            tmp[k++] = a[i++]; // 32 54321
            ans += high - j + 1;
        }
        else
            tmp[k++] = a[j++];
    }
    while (i <= mid)
        tmp[k++] = a[i++];
    while (j <= high)
        tmp[k++] = a[j++];
    for (long long i = 0; i < k; i++)
        a[low + i] = tmp[i];
    delete tmp;
}
void MergePass(long long a[], long long length, long long n)
{
    long long i;
    for (i = 0; i + 2 * length < n; i += 2 * length)
        Merge(a, i, i + length - 1, i + 2 * length - 1);
    if (i + length - 1 < n)
        Merge(a, i, i + length - 1, n - 1);
}
void MergeSort(long long a[], long long n)
{
    long long length;
    for (length = 1; length < n; length *= 2)
        MergePass(a, length, n);
}
int main()
{
    long long n;
    cin >> n;
    for (long long i = 0; i < n; i++)
        cin >> arr[i];
    MergeSort(arr, n);
    cout << ans << endl;
}