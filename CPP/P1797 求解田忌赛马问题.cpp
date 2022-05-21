#include <iostream>
#include <algorithm>
using namespace std;
long long a[100000], b[100000];
long long money = 0;
int main(int argc, char const* argv[])
{
    long long n;
    cin >> n;
    for (long long i = 0; i < n; i++)
        cin >> a[i];
    for (long long i = 0; i < n; i++)
        cin >> b[i];
    sort(a, a + n);
    sort(b, b + n);
    int lefta = 0, leftb = 0, righta = n - 1, rightb = n - 1;
    while (lefta <= righta)
    {
        if (a[righta] > b[rightb])
        {
            money += 200;
            righta--;
            rightb--;
        }
        else if (a[righta] < b[rightb])
        {
            money -= 200;
            lefta++;
            rightb--;
        }
        else if (a[righta] == b[rightb])
        {
            if (a[lefta] > b[leftb])
            {
                money += 200;
                lefta++;
                leftb++;
            }
            else if (a[lefta] <= b[leftb] && a[lefta] < b[rightb])
            {
                money -= 200;
                lefta++;
                rightb--;
            }
            else
            {
                break;
            }
        }
    }
    cout << money << endl;
}
