#include <stdio.h>
int main()
{
    int n, m;
    while (scanf("%d", &n) != EOF)
    {
        int year = 2007, month = 10, day = 10;
        day += n;
        for (; day > 31;)
        {

            if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
            {
                if (day > 31)
                {
                    day -= 31;
                    month += 1;
                }
            }
            if (month == 4 || month == 6 || month == 9 || month == 11)
            {
                if (day > 30)
                {
                    day -= 30;
                    month += 1;
                }
            }
            if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
                if (month == 2)
                {
                    if (day > 29)
                    {
                        day -= 29;
                        month += 1;
                    }
                }
            if (!((year % 4 == 0 && year % 100 != 0) || year % 400 == 0))
                if (month == 2)
                {
                    if (day > 28)
                    {
                        day -= 28;
                        month += 1;
                    }
                }
            if (month > 12)
            {
                year += 1;
                month -= 12;
            }
        }
        if(month<10&&day>=10)
        printf("%d-0%d-%d\n", year, month, day);
        if(day<10&&month>=10)
        printf("%d-%d-0%d\n", year, month, day);
        if(day<10&&month<10)
        printf("%d-0%d-0%d\n", year, month, day);
        if(day>=10&&month>=10)
        printf("%d-%d-%d\n", year, month, day);
    }
}