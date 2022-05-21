#include <iostream>
using namespace std;
int ans = 0;
int arr[500000];
void Merge(int a[], int low, int mid, int high) //合并两个
{
    int i = low, j = mid + 1, k = 0;
    int* tmp = new int[high - low + 1];
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
    for (int i = 0; i < k; i++)
        a[low + i] = tmp[i];
    delete tmp;
}
void MergePass(int a[], int length, int n)
{
    int i;
    for (i = 0; i + 2 * length < n; i += 2 * length)
        Merge(a, i, i + length - 1, i + 2 * length - 1);
    if (i + length - 1 < n)
        Merge(a, i, i + length - 1, n - 1);
}
void MergeSort(int a[], int n)
{
    int length;
    for (length = 1; length < n; length *= 2)
        MergePass(a, length, n);
}
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    MergeSort(arr, n);
    cout << ans << endl;
}