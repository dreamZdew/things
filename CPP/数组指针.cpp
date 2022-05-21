#include <iostream>
using namespace std;
int main()
{
    int i, j;
    char str1[100], str2[100];
    cin >> str1 >> str2;
    int l1, l2;
    for (l1 = 0; str1[l1] != '\0'; l1++)
        ;
    for (i = l1, j = 0; str2[j] != '\0'; i++, j++)
    {
        str1[i] = str2[j];
    }
    str1[i]='\0';
    cout << str1;
}