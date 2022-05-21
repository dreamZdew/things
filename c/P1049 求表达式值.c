#include <stdio.h>
int main()
{
    int a;
    float x, y;
    while (scanf("%d %f %f", &a, &x, &y) != EOF)
    {
        printf("%.6f\n", x + a % 3 * (int)(x + y) % 2 / 4);
    }
}