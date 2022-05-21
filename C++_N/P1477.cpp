#include <iostream>
#include <algorithm>
using namespace std;
int N;
double T;
struct goldheap
{
    double m, v, ave;
} heap[100];

bool cmp(goldheap a, goldheap b)
{
    return a.ave > b.ave;
}

int main()
{
    double money = 0;
    cin >> N >> T;
    for (int i = 0; i < N; i++)
    {
        cin >> heap[i].m >> heap[i].v;
        heap[i].ave = heap[i].v / heap[i].m;
    }
    sort(heap, heap + N, cmp);
    int i;
    for (i = 0; i < N && T - heap[i].m > 0; i++)
    {
        T -= heap[i].m;
        money += heap[i].v;
    }
    money += T * heap[i].ave;
    printf("%.2f\n", money);
}