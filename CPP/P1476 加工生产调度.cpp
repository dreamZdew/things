#include <iostream>
#include <algorithm>
using namespace std;
int arr[2000];
int n;
struct node
{
    int a, b, mintime, id;
} Node[2000], originNode[2000];
int cmp(node x, node y)
{
    return x.mintime < y.mintime;
}
int main()
{
    while (cin >> n)
    {
        for (int i = 0; i < n; i++)
        {
            cin >> Node[i].a;
            Node[i].id = i ;
        }
        for (int i = 0; i < n; i++)
        {
            cin >> Node[i].b;
            originNode[i] = Node[i];
        }
        for (int i = 0; i < n; i++)
        {
            if (Node[i].a > Node[i].b)
                Node[i].mintime = Node[i].b;
            else
                Node[i].mintime = Node[i].a;
        }
        sort(Node, Node + n, cmp);
        int j = 0, k = n - 1;
        for (int i = 0; i < n; i++)
        {
            if (Node[i].mintime == Node[i].a)
            {
                arr[j] = Node[i].id;
                j++;
            }
            else
            {
                arr[k] = Node[i].id;
                k--;
            }
        }
        int sum1 = 0, sum2 = 0;
        for (int i = 0; i < n; i++)
        {
            sum1 += originNode[arr[i]].a;
            sum2 = max(sum1, sum2);
            sum2 += originNode[arr[i]].b;
        }
        cout << sum2 << endl;

    }
}