#include <stdio.h>
#include <string.h>
int main()
{
    char a[100];
    while (scanf("%s", a) != EOF)
    {
        for (int i = 0; i < strlen(a); i++)
        {
            if (a[i] == 'a' || a[i] == 'A')
                printf(".-");
            if (a[i] == 'b' || a[i] == 'B')
                printf("-...");
            if (a[i] == 'c' || a[i] == 'C')
                printf("-.-.");
            if (a[i] == 'd' || a[i] == 'D')
                printf("-..");
            if (a[i] == 'e' || a[i] == 'E')
                printf(".");
            if (a[i] == 'f' || a[i] == 'F')
                printf("..-.");
            if (a[i] == 'g' || a[i] == 'G')
                printf("--.");
            if (a[i] == 'h' || a[i] == 'H')
                printf("....");
            if (a[i] == 'i' || a[i] == 'I')
                printf("..");
            if (a[i] == 'j' || a[i] == 'J')
                printf(".---");
            if (a[i] == 'k' || a[i] == 'K')
                printf("-.-");
            if (a[i] == 'l' || a[i] == 'L')
                printf(".-..");
            if (a[i] == 'm' || a[i] == 'M')
                printf("--");
            if (a[i] == 'n' || a[i] == 'N')
                printf("-.");
            if (a[i] == 'o' || a[i] == 'O')
                printf("---");
            if (a[i] == 'p' || a[i] == 'P')
                printf(".--.");
            if (a[i] == 'q' || a[i] == 'Q')
                printf("--.-");
            if (a[i] == 'r' || a[i] == 'R')
                printf(".-.");
            if (a[i] == 's' || a[i] == 'S')
                printf("...");
            if (a[i] == 't' || a[i] == 'T')
                printf("-");
            if (a[i] == 'u' || a[i] == 'U')
                printf("..-");
            if (a[i] == 'v' || a[i] == 'V')
                printf("...-");
            if (a[i] == 'w' || a[i] == 'W')
                printf(".--");
            if (a[i] == 'x' || a[i] == 'X')
                printf("-..-");
            if (a[i] == 'y' || a[i] == 'Y')
                printf("-.--");
            if (a[i] == 'z' || a[i] == 'Z')
                printf("--..");
            if (a[i] == '0')
                printf(".----");
            if (a[i] == '1')
                printf("..---");
            if (a[i] == '2')
                printf("...--");
            if (a[i] == '3')
                printf("....-");
            if (a[i] == '4')
                printf(".....");
            if (a[i] == '5')
                printf("-....");
            if (a[i] == '6')
                printf("--...");
            if (a[i] == '7')
                printf("---..");
            if (a[i] == '8')
                printf("----.");
            if (a[i] == '9')
                printf("-----");
            if(i<strlen(a)-1)
            printf("===");
        }
        printf("\n");
    }
}
