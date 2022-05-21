#include <stdio.h>
#include <string.h>
int main()
{
    char str[1000];
    while (gets(str)!=NULL)
    {
        int i, j, k=0;
        for (i = 0; str[i] != '\0'; i++)
        {
            if (str[i] != ' ' && str[i + 1] == ' ')
                k++;
        }
        j = strlen(str);
        if (str[j - 1] != ' ')
            k++;
        printf("%d\n", k);
    }
}