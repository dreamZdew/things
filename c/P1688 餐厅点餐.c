#include <stdio.h>
#include <string.h>
void bubble(int arr[])
{
    int i, j, temp, len = strlen(arr);
    for (i = 0; i < len - 1; i++)
        for (j = 0; j < len - 1 - i; j++)
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
}
int main()
{
    int n;
    scanf("%d", &n);
    while (n--)
    {
        int a, b, c, d, e, min, max, i, j;
        scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);
        int aa[a], bb[b], cc[c], dd[d], ee[e];
        for (int i = 0; i < a; i++)
            scanf("%d", &aa[i]); //aa
        for (int i = 0; i < b; i++)
            scanf("%d", &bb[i]); //bb
        for (int i = 0; i < c; i++)
            scanf("%d", &cc[i]); //cc
        for (int i = 0; i < d; i++)
            scanf("%d", &dd[i]); //dd
        for (int i = 0; i < e; i++)
            scanf("%d", &ee[i]); //ee
        bubble(aa);
        bubble(bb);
        bubble(cc);
        bubble(dd);
        bubble(ee);
        scanf("%d %d", &min, &max);
        int sum, ans = 0;

        //8种情况
        for (int i = 0; i < a; i++)
            for (int j = 0; j < b; j++)
                for (int r = 0; r < d; r++)
                    for (int y = r + 1; y < d; y++)
                        for (int w = 0; w < e; w++)
                            for (int h = w + 1; h < e; h++)
                            {
                                sum = aa[i] + bb[j] + dd[r] + dd[y] + ee[w] + ee[h];
                                if (sum >= min && sum <= max)
                                    ans++;
                            } //一汤一饭两荤两素
        for (int i = 0; i < a; i++)
            for (int j = 0; j < b; j++)
                for (int r = 0; r < d; r++)
                    for (int w = 0; w < e; w++)
                        for (int h = w + 1; h < e; h++)
                        {
                            sum = aa[i] + bb[j] + dd[r] + ee[w] + ee[h];
                            if (sum >= min && sum <= max)
                                ans++;
                        } //一汤一饭一荤两素
        for (int i = 0; i < a; i++)
            for (int j = 0; j < b; j++)
                for (int r = 0; r < d; r++)
                    for (int y = r + 1; y < d; y++)
                        for (int w = 0; w < e; w++)
                        {
                            sum = aa[i] + bb[j] + dd[r] + dd[y] + ee[w];
                            if (sum >= min && sum <= max)
                                ans++;
                        } //一汤一饭两荤一素
        for (int i = 0; i < a; i++)
            for (int j = 0; j < b; j++)
                for (int r = 0; r < d; r++)
                    for (int w = 0; w < e; w++)
                    {
                        sum = aa[i] + bb[j] + dd[r] + ee[w];
                        if (sum >= min && sum <= max)
                            ans++;
                    } //一汤一饭一荤一素
        for (int i = 0; i < c; i++)
            for (int r = 0; r < d; r++)
                for (int y = r + 1; y < d; y++)
                    for (int w = 0; w < e; w++)
                        for (int h = w + 1; h < e; h++)
                        {
                            sum = cc[i] + dd[r] + dd[y] + ee[w] + ee[h];
                            if (sum >= min && sum <= max)
                                ans++;
                        } //一面两荤两素
        for (int i = 0; i < c; i++)
            for (int r = 0; r < d; r++)
                for (int w = 0; w < e; w++)
                    for (int h = w + 1; h < e; h++)
                    {
                        sum = cc[i] + dd[r] + ee[w] + ee[h];
                        if (sum >= min && sum <= max)
                            ans++;
                    } //一面一荤两素
        for (int i = 0; i < c; i++)
            for (int r = 0; r < d; r++)
                for (int y = r + 1; y < d; y++)
                    for (int w = 0; w < e; w++)
                    {
                        sum = cc[i] + dd[r] + dd[y] + ee[w];
                        if (sum >= min && sum <= max)
                            ans++;
                    } //一面两荤一素
        for (int i = 0; i < c; i++)
            for (int r = 0; r < d; r++)
                for (int w = 0; w < e; w++)
                {
                    int sum = cc[i] + dd[r] + ee[w];
                    if (sum >= min && sum <= max)
                        ans++;
                } //一面一荤一素
        printf("%d\n", ans);
    }
}