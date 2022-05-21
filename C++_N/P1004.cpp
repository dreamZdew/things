#include <iostream>
#include <string>
#include <list>
using namespace std;
int main(int argc, char const *argv[])
{
    string a, b;
    while (cin >> a >> b)
    {
        int maxl, minl;
        if (a.length() > b.length())
        {
            maxl = a.length();
            minl = b.length();
        }
        else
        {
            maxl = b.length();
            minl = a.length();
        }
        list<int> arr;
        for (int i = minl - 1; i >= 0; i--)
            arr.push_front(a[i] - 48 + b[i] - 48);

        for (auto i = arr.rbegin(); i != arr.rend(); i++)
        {

            if (*i >= 10)
            {
                i++;
                auto z = i;
                i--;
                *z += *i / 10;
                *i = *i % 10;
            }
        }
        for (auto i : arr)
        {
            cout << i;
        }
        cout << endl;
    }

    return 0;
}
