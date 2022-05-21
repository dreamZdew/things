/*反位数*/
int fanwei(int n)
{
    int i, k = 10, t = 0;
    for (i = n; i != 0; i /= 10)
    {
        t += i % 10;
        t *= 10;
    }
    return t /= 10;
}
/*判断素数*/
int prime(int n)
{
    int i, t, k;
    for (i = 2; i < n; i++)
    {
        if (n % i == 0)
        {
            return 0; /*不是素数*/
        }
    }
    return 1; /*是素数*/
}
/*各位求和*/
int qiuhe(int n)
{
    int i,j=0,k;
    for(;n;)
    {
        j+=n%10;
        n/=10;
    }
    return j;
}
void fan(char str[]) //反转字符串
{
    char a[100];
    for (int i = 0; i < strlen(str); i++)
        a[i] = str[strlen(str) - i - 1];
    for (int i = 0; i < strlen(str); i++)
        str[i] = a[i];
}