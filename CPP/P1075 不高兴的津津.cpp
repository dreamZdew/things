#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(int argc, char const *argv[])
{
    int n;
    while (cin >> n)
    {
        int day = 0,time=0;
        int a[10], b[10];
        a[1] = n;
        cin >> b[1];
        for (int i = 2; i <= 7; i++)
        {
            cin >> a[i] >> b[i];
        }
        for (int i = 1; i <= 7; i++)
        {
            if (a[i] + b[i] > 8 && a[i] + b[i] > time)
            {
                time=a[i] + b[i];
                day = i;
            }
        }
        cout << day << endl;
    }

    return 0;
}
