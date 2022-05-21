#include <iostream>
#include <algorithm>
int a[3000], b[3000], c[3000], d[3000];
int sum1[10000000], sum2[10000000];
using namespace std;

int find(int target,int t)
{
    int samecount = 0;
    int l=0, h=t-1;
    while (l<h)
    {
        int mid =  (l + h) / 2;
        if (target <= sum2[mid])
            h = mid;
        else
            l = mid + 1;
    }
    while (target==sum2[l]&&l<t)
    {
        samecount++;
        l++;
    }
    return samecount;
}
int main()
{
    int nn;
    cin >> nn;
    while (nn--)
    {
        int ans = 0;
        int n;
        cin >> n;
        int t = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i] >> b[i] >> c[i] >> d[i];
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                sum1[t] = a[i] + b[j];
                sum2[t] = c[i] + d[j];
                t++;
            }
        }
        sort(sum1, sum1 + t);
        sort(sum2, sum2 + t);

        for (int i = 0; i < t; i++)
        {
            ans+=find(-sum1[i], t);
        }
        cout << ans << endl;
    }
}