#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<long long> sq;
long long n, m;
long long aa[10000], bb[10000];

int main(int argc, char const *argv[])
{
    cin >> n >> m;
    for (long long i = 1; i <= n; i++)
    {
        cin >> aa[i] >> bb[i];
        long long a = aa[i], b = bb[i];
        while (a != b)
        {
            if (a > b)
            {
                sq.push_back(b * b);
                a -= b;
            }
            else
            {
                sq.push_back(a * a);
                b -= a;
            }
        }
        sq.push_back(a * a);
    }
    sort(sq.begin(), sq.end(), greater<long long>());

    long long ans = 0;
    for (int i = 0; i < m; i++)
    {
        ans += sq[i];
    }
    cout << ans << endl;

    return 0;
}
