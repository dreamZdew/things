#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
    int n;
    while (cin >> n)
    {
        for (int i = 0; i < n; i++)
        {
            int a, b;
            cin >> a >> b;
            cout << a / b << " " << a % b << endl;
        }
    }

    return 0;
}
