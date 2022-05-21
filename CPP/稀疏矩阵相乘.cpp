#include <stdio.h>
#include <stdlib.h>
struct Triple
{
    int i, j;
    int e;
};

struct RLSMatrix
{
    struct Triple data[100];
    int rpos[100];
    int mu, nu, tu;
};
void Mult(struct RLSMatrix M, struct RLSMatrix N, struct RLSMatrix &Q)
{

    int arow, tp, p, brow, t, q, ccol;
    if (M.nu != N.mu)
        exit(0);
    Q.mu = M.mu;
    Q.nu = N.nu;
    Q.tu = 0;
    if (M.tu * N.tu != 0)
    {
        for (arow = 1; arow <= M.mu; arow++)
        {
            int ctemp[100] = {0};
            Q.rpos[arow] = Q.tu + 1;
            if (arow < M.mu)
                tp = M.rpos[arow + 1];
            else
                tp = M.tu + 1;
            for (p = M.rpos[arow]; p < tp; p++)
            {
                brow = M.data[p].j;
                if (brow < N.mu)
                    t = N.rpos[brow + 1];
                else
                    t = N.tu + 1;
                for (q = N.rpos[brow]; q < t; q++)
                {
                    ccol = N.data[q].j;
                    ctemp[ccol] += M.data[p].e * N.data[q].e;
                }
            }
            for (ccol = 1; ccol <= Q.nu; ccol++)
            {
                if (ctemp[ccol])
                {
                    if (++Q.tu > 100)
                        exit(0);
                    Q.data[Q.tu].i = arow;
                    Q.data[Q.tu].j = ccol;
                    Q.data[Q.tu].e = ctemp[ccol];
                }
            }
        }
    }
}
void input(struct RLSMatrix &M)
{
    printf("输入矩阵行数、列数、非零元个数：");
    scanf("%d %d %d", &M.mu, &M.nu, &M.tu);
    int t = 1, row = 0, count = 0;
    M.rpos[1] = 0;
    for (t = 1; t <= M.tu; t++)
    {
        printf("输入矩阵行数、列数、元素：");
        scanf("%d %d %d", &M.data[t].i, &M.data[t].j, &M.data[t].e);
        if (t == 1)
        {
            row++;
            count++;
            M.rpos[1] = 1;
        }
        if (t > 1)
        {
            if (M.data[t].i == M.data[t - 1].i)
            {
                count++;
            }

            else
            {
                row++;
                M.rpos[row] = count + 1;
                count++;
            }
        }
    }
    count++;
    M.rpos[row + 1] = count;
}
void outputrow(struct RLSMatrix M)
{
    for (int i = 1; i <= M.mu; i++)
    {
        printf("%d ", M.rpos[i]);
    }
}
void output(struct RLSMatrix M)
{
    printf("\n");
    int i, j, k = 1;
    for (i = 1; i <= M.mu; i++)
    {
        for (j = 1; j <= M.nu; j++)
        {
            if (M.data[k].i == i && M.data[k].j == j)
            {
                printf("%4d", M.data[k].e);
                k++;
            }
            else
                printf("%4d", 0);
        }
        printf("\n");
    }
    printf("\n");
}
int main()
{
    struct RLSMatrix M;
    struct RLSMatrix T;
    struct RLSMatrix Q;
    input(M);
    /*
    3 4 4
    1 1 3
    1 4 5
    2 2 -1
    3 1 2

    4 2 4
    1 2 2
    2 1 1
    3 1 -2
    3 2 4
    */
    output(M);
    input(T);
    output(T);
    Mult(M, T, Q);
    output(Q);
}