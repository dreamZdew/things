#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int n, k;
    while (cin >> n >> k)
    {
        n /= pow(10, k);
        cout << n % 10 << endl;
    }
}