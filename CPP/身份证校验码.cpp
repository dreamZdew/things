#include <iostream>
#include <string>
using namespace std;
int main()
{
    string a = "32040120020913221";
    int b[] = {7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2};
    int sum = 0;
    for (size_t i = 0; i < a.size(); i++)
        sum += (a[i] - 48) * b[i];
    sum %= 11;
    sum = 12 - sum;
    if (sum == 10)
        cout << "X" << endl;
    else
        cout << sum << endl;
}