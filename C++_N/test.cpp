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
        int m = arr1.length(); // mΪarr1�ĳ���
        int n = arr2.length(); // nΪarr2�ĳ���
        LCS(arr1, arr2);       //���dp, ���Ҹ�b[][]���鸳ֵ
        printf("���: ");
        Output(m, n); //�����ˮ��ȡ��
        printf("\n");
    }
}

void Output(int i, int j)
{                         //���õݹ������ˮ��ȡ��
    if (i == 0 && j == 0) //������
        return;
    if (i == 0)
    { // arr1��ϣ����arr2��ʣ�ಿ��
        Output(i, j - 1);
        printf("%c", arr2[j - 1]);
        return;
    }
    else if (j == 0)
    { // arr2��ϣ����arr1��ʣ�ಿ��
        Output(i - 1, j);
        printf("%c", arr1[i - 1]);
        return;
    }
    if (b[i][j] == 0)
    { // arr1[i-1]=arr2[j-1]�����
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
b[i][j]=0��ʾarr1[i-1]=arr2[j-1]��
b[i][j]=1��ʾarr1[i-1]��arr2[j-1]����dp[i-1][j]>dp[i][j-1]��
b[i][j]=2��ʾarr1[i-1]��arr2[j-1]����dp[i-1][j]��dp[i][j-1]��
*/
string LCS(string aaaa, string bbbb) //���a��b���������
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