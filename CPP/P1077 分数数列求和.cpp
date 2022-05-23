#include <iostream>
#include <numeric>
using namespace std;
void fun(long long a1, long long a2, long long b1, long long b2, long long &c1, long long &c2)
{
    c2 = a2 * b2;
    c1 = a1 * b2 + b1 * a2;
}
int main(int argc, char const *argv[])
{

    long long arr1[1000], arr2[1000];
    arr1[0] = 0;
    arr2[0] = 1;
    arr1[1] = -3;
    arr2[1] = 2;
    arr1[2] = 5;
    arr2[2] = 3;
    for (long long i = 3; i < 105; i++)
    {
        arr2[i] = arr2[i - 1] + arr2[i - 2];
    }
    for (long long i = 1; i < 100; i++)
    {
        arr1[i] = arr2[i + 1];
        if (i % 2 == 1)
            arr1[i] *= -1;
    }

    long long n;
    while (cin >> n)
    {
        double sum=2;
        long long a = 2, b = 1;
        for (long long i = 0; i < n; i++)
        {
            sum+=(double)arr1[i]/(double)arr2[i];
        }
       
        printf("%.4f\n", sum);
    }
    return 0;
}
