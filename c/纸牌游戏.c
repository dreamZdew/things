// 40．纸牌游戏（限1 人完成）
// 描述：现有编号为1—52的纸牌，正面向上，从第2张开始，凡是2的倍数的牌翻一次，直到最后一张牌；
// 然后从第3张开始，凡是3的倍数的牌翻一次，直到最后一张牌；然后从第4张开始，凡是4的倍数的牌翻一次，直到最后一张牌；再依次以5的倍数、6的倍数、7的倍数一直到52的倍数的翻过，此时正面向上的牌有哪些？
#include <stdio.h>
#include <string.h>
#include <math.h>
void CardGameLoop();
void CardGameFactor();
void CardGamePower();
int main()
{
    CardGameLoop();
    CardGameFactor();
    CardGamePower();
}
void CardGameLoop()
{
    int arr[60];
    for (int i = 1; i <= 52; i++)
        arr[i] = 1;
    for (int i = 2; i <= 52; i++)
        for (int j = i; j <= 52; j++)
            if (j % i == 0)
                arr[j] *= (-1);
    for (int i = 1; i <= 52; i++)
        if (arr[i] == 1)
            printf("%d\n", i);
}
//有奇数个因数
void CardGameFactor()
{
    for (int i = 1; i <= 52; i++)
    {
        //判断每个数的因数个数
        int count = 0;
        for (int j = 1; j <= i / 2; j++)
        {
            if (i % j == 0)
                ++count;
        }
        if (count % 2 == 0)
            printf("%d\n", i);
    }
}
//是平方数
void CardGamePower()
{
    for (int i = 1; i <= 52; i++)
        if ((int)sqrt(i) == sqrt(i))
            printf("%d\n", i);
}