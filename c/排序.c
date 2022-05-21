#include <stdio.h>
#include <stdlib.h>
// 1）内部排序方法有哪些？按类别描述各种排序算法，分析稳定性和性能。（着重分析希尔排序、快速排序、堆排序、归并排序）
//（2）堆排序属于哪一类？ 已知大顶堆{25，20，9，6，5，7，8，2，4}，当输出关键字25以后，用最后一个元素替换掉堆顶元素，描述重新调整成大顶堆的过程。
void HeapAdjust(int a[], int s, int m)
{
    int rc = a[s];
    for (int j = 2 * s; j <= m; j *= 2)
    {
        if (j < m && a[j] < a[j + 1])
            j++;
        if (rc >= a[j])
            break;
        a[s] = a[j];
        s = j;
    }
    a[s] = rc;
}
void HeapSort(int a[])
{
    int length=sizeof(a) / sizeof(int);
    for (int i = length / 2; i >= 0; i--)
        HeapAdjust(a, i, length);
    for (int i = length; i >0; i--)
    {
        int t = a[0];
        a[0] = a[i];
        a[i] = t;
        HeapAdjust(a, 0, i - 1);
    }
}
int main()
{
    int a[] = {25, 20, 9, 6, 5, 7, 8, 2, 4};int length=sizeof(a) / sizeof(int);
    HeapSort(a);
    for (int i = 0; i < sizeof(a) / sizeof(int); i++)
    printf("%d ",a[i]);
    
}