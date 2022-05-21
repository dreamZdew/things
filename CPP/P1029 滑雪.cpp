#include <iostream>
#include <algorithm>
using namespace std;
int dp[200][200];
int matrix[200][200];
struct node
{
    int x, y, h;
} Node[10000];
bool cmp(node a, node b)
{
    return a.h < b.h;
}
int max(int a, int b, int c, int d)
{
    if (a < b)
        a = b;
    if (a < c)
        a = c;
    if (a < d)
        a = d;
    return a;
}

int main()
{
    int R, C;
    while (cin >> R >> C)
    {
        int k = 0;
        for (int i = 0; i < R; i++)
            for (int j = 0; j < C; j++, k++)
            {
                cin >> matrix[i][j];
                Node[k].x = i;
                Node[k].y = j;
                Node[k].h = matrix[i][j];
                dp[i][j] = 0;
            }
        sort(Node, Node + k, cmp);
        dp[Node[0].x][Node[0].y] = 1;
        for (int i = 1; i < k; i++)
        {
            int arr[4] = { 0 };
            if ((Node[i].x - 1 >= 0 && Node[i].x - 1 <= R - 1 && Node[i].y >= 0 && Node[i].y <= C - 1) && Node[i].h > matrix[Node[i].x - 1][Node[i].y]) //数组越界检查
                arr[0] = dp[Node[i].x - 1][Node[i].y];
            if ((Node[i].x + 1 >= 0 && Node[i].x + 1 <= R - 1 && Node[i].y >= 0 && Node[i].y <= C - 1) && Node[i].h > matrix[Node[i].x + 1][Node[i].y])
                arr[1] = dp[Node[i].x + 1][Node[i].y];
            if ((Node[i].x >= 0 && Node[i].x <= R - 1 && Node[i].y - 1 >= 0 && Node[i].y - 1 <= C - 1) && Node[i].h > matrix[Node[i].x][Node[i].y - 1])
                arr[2] = dp[Node[i].x][Node[i].y - 1];
            if ((Node[i].x >= 0 && Node[i].x <= R - 1 && Node[i].y + 1 >= 0 && Node[i].y + 1 <= C - 1) && Node[i].h > matrix[Node[i].x][Node[i].y + 1])
                arr[3] = dp[Node[i].x][Node[i].y + 1];
            dp[Node[i].x][Node[i].y] = max(arr[0], arr[1], arr[2], arr[3]) + 1;
        }
        int ans = 0;
        for (int i = 0; i < R; i++)
            for (int j = 0; j < C; j++)
                if (dp[i][j] > ans)
                    ans = dp[i][j];
        cout << ans << endl;
    }
}