#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;
void Output(int i, int j);
string LCS(string a, string b);

string arr1, arr2;
int dp[100][100];
int b[100][100];
int main()
{
    while (cin >> arr1 >> arr2)
    {
        memset(b, -1, sizeof(b));
        int m = arr1.length(); // m为arr1的长度
        int n = arr2.length(); // n为arr2的长度
        LCS(arr1, arr2);       //求出dp, 并且给b[][]数组赋值
        printf("结果: ");
        Output(m, n); //输出新水果取名
        printf("\n");
    }
}

void Output(int i, int j)
{                         //利用递归输出新水果取名
    if (i == 0 && j == 0) //输出完毕
        return;
    if (i == 0)
    { // arr1完毕，输出arr2的剩余部分
        Output(i, j - 1);
        printf("%c", arr2[j - 1]);
        return;
    }
    else if (j == 0)
    { // arr2完毕，输出arr1的剩余部分
        Output(i - 1, j);
        printf("%c", arr1[i - 1]);
        return;
    }
    if (b[i][j] == 0)
    { // arr1[i-1]=arr2[j-1]的情况
        Output(i - 1, j - 1);
        printf("%c", arr1[i - 1]);
        return;
    }
    else if (b[i][j] == 1)
    {
        Output(i - 1, j);
        printf("%c", arr1[i - 1]);
        return;
    }
    else
    {
        Output(i, j - 1);
        printf("%c", arr2[j - 1]);
        return;
    }
}

/*
b[i][j]=0表示arr1[i-1]=arr2[j-1]；
b[i][j]=1表示arr1[i-1]≠arr2[j-1]并且dp[i-1][j]>dp[i][j-1]；
b[i][j]=2表示arr1[i-1]≠arr2[j-1]并且dp[i-1][j]≤dp[i][j-1]。
*/
string LCS(string aaaa, string bbbb) //求解a和b的最长子序列
{
    string z;
    for (int i = 0; i <= aaaa.length(); i++)
    {
        for (int j = 0; j <= bbbb.length(); j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else if (aaaa[i - 1] == bbbb[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                b[i][j] = 0;
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                if (dp[i - 1][j] > dp[i][j - 1])
                    b[i][j] = 1;
                else if (dp[i - 1][j] <= dp[i][j - 1])
                    b[i][j] = 2;
            }
        }
    }

    int k = dp[aaaa.length()][bbbb.length()];
    int i = aaaa.length(), j = bbbb.length();
    while (k > 0)
    {
        if (dp[i][j] == dp[i - 1][j])
            i--;
        else if (dp[i][j] == dp[i][j - 1])
            j--;
        else
        {
            z += aaaa[i - 1];
            i--;
            j--;
            k--;
        }
    }
    return z;
}