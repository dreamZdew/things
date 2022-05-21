#include <iostream>
using namespace std;
void move(char yuan, char mu)
{
    cout << yuan << "-->" << mu << endl;
}
void ha(int n, char yuan, char zhong, char mu)
{
    if (n == 1)
        move(yuan, mu);
    else
    {
        ha(n - 1, yuan, mu, zhong);
        move(yuan, mu);
        ha(n - 1, zhong, yuan, mu);
    }
}
int main()
{
    int n;
    cin >> n;
    ha(n,'A','B','C');
}