#include <stdio.h>
#include <string.h>
void fan(char str[]) //反转字符串
{
    char a[100];
    for (int i = 0; i < strlen(str); i++)
        a[i] = str[strlen(str) - i - 1];
    for (int i = 0; i < strlen(str); i++)
        str[i] = a[i];
}
int main()
{
    char str[100][101], minStr[101], subStr[101], revSubStr[101];
    unsigned int i, j, t, m, n, substrlen, found, minlen;
    scanf("%d", &t); //测试数据组数
    while (t--)
    {
        scanf("%d", &n);
        minlen = 101;
        for (i = 0; i < n; i++)
        { //读入所有数据串
            scanf("%s", str[i]);
            if (strlen(str[i]) < minlen)
            { //查找最短的字符串
                minlen = strlen(str[i]);
                m = i;
            }
        }
        strcpy(minStr, str[m]); //查找到最短的串
        substrlen = minlen;
        while (substrlen > 0)
        { //取子串长度
            for (i = 0; i <= minlen - substrlen; i++)
            {
                strncpy(subStr, minStr + i, substrlen); //取正向子串
                subStr[substrlen] = '\0';
                strncpy(revSubStr, minStr + i, substrlen); //取逆向子串
                revSubStr[substrlen] = '\0';
                fan(revSubStr);
                found = 1;
                for (j = 0; j < n; j++)
                { //在所有子串中查找是否包含正或者逆向子串
                    if (strstr(str[j], subStr) == NULL && strstr(str[j], revSubStr) == NULL)
                    {
                        found = 0;
                        break;
                    } //在str[j]中不存在子串
                }
                if (found)
                    break; //找到子串，结束
            }
            if (found)
                break;   //找到子串，结束
            substrlen--; //没找到子串子串长度减1,再试
        }
        printf("%d\n", substrlen); //输出找到子串长度
    }
}