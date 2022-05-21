#include <stdio.h>
#include <string.h>
int main()
{
    char s1[100], s2[100];
    scanf("%s", &s1);
    scanf("%s", &s2);
    for (int i = 0, j = 0; i < strlen(s1) && j < strlen(s2);)
    {
        if (s1[i] == s2[j])
        {
            i++;
            j++;
        }
        else
        {
            i = i - j + 1;
            j = 0;
        }
        if (j == strlen(s2))
        {
            printf("%d", i - j + 1);
            break;
        }
    }
}
