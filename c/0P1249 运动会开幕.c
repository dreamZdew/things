#include <stdio.h>
#include <string.h>
struct meeting
{
    int num;
    char country[50];
    int pop;
    char comtinent[50];
};

int main()
{
    struct meeting me[300];
    struct meeting t;
    int n, i, j, k, m;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
        scanf("%d %s %d %s", &me[i].num, &me[i].country, &me[i].pop, &me[i].comtinent);
    for (i = 0; i < n - 1; i++)
        for (j = 0; j < n - 1 - i; j++)
            if (strcmp(me[j].country, me[j + 1].country) > 0)
            {
                t = me[j];
                me[j] = me[j + 1];
                me[j + 1] = t;
            }
    printf("\n");
    for (i = 0; i < n; i++)
        if (strcmp(me[i].country, "China") != 0)
        {
            printf("%d %s %d %s\n", me[i].num, me[i].country, me[i].pop, me[i].comtinent);
        }
    for (i = 0; i < n; i++)
        if (strcmp(me[i].country, "China") == 0)
            printf("%d %s %d %s\n", me[i].num, me[i].country, me[i].pop, me[i].comtinent);
}