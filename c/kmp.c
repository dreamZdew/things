#include <stdio.h>
#include <string.h>
void getnext(char str[], int next[])
{
    next[1] = 0;
    int i=1,j=0;
    while (i < strlen(str))
    {
        if (j == 0 || str[i] == str[j])
        {
            i++;
            j++;
            next[i] = j;
        }
        else
            j = next[j];
    }
}
int main()
{
    char s1[100], s2[100];
    scanf("%s\n%s",&s1,&s2);
    int next[100];
    getnext(s2, next);
    for (int i = 0, j = 0; i < strlen(s1) && j < strlen(s2);)
    {
        if (j == 0 || s1[i] == s2[j])
        {
            i++;
            j++;
        }
        else
        {
            j = next[j];
        }
        if (j >= strlen(s2))
        {
            printf("%d", i-strlen(s2)+1);
            break;
        }
    }
}
