#include <stdio.h>
struct Triple
{
    int i, j;
    int e;
};
struct TSMatrix
{
    struct Triple data[100];
    int mu, nu, tu;
};
void FastT(struct TSMatrix M, struct TSMatrix T)
{
    int col;
    int num[100], cpot[100];
    T.mu = M.nu;
    T.nu = M.nu;
    T.tu = M.tu;
    if (T.tu)
    {
        for (col = 1; col <= M.nu; col++)
            num[col] = 0;
        for (int t = 1; t <= M.nu; t++)
            ++num[M.data[t].j];
        cpot[1] = 1;
        for (col = 2; col <= M.nu; col++)
            cpot[col] = cpot[col - 1] + num[col - 1];
        for (int p = 1; p <= M.tu; p++)
        {
            col = M.data[p].j;
            int q = cpot[col];
            T.data[q].i = M.data[p].j;
            T.data[q].j = M.data[p].i;
            T.data[q].e = M.data[p].e;
            cpot[col]++;
        }
    }
}
void input(struct TSMatrix M)
{
    printf("输入矩阵行数、列数、非零元个数：");
    scanf("%d %d %d", M.mu, M.nu, M.tu);
    int t = 1;
    for (t = 1; t <= M.tu; t++)
        scanf("%d %d %d", M.data[t].i, M.data[t].i, M.data[t].e);
}
void output(struct TSMatrix M)
{
    int i, j, k = 1;
    for (i = 1; i <= M.nu; i++)
    {
        for (j = 1; i <= M.mu; j++)
        {
            if (M.data[k].i == i && M.data[k].j == j)
                {
                    printf("%d ", M.data[k].e);k++;
                }
            else
                printf("0 ");
        }
        printf("\n");
    }
}
int main()
{
    struct TSMatrix M;
    struct TSMatrix T;
    input(M);
    FastT(M, T);output(T);
}