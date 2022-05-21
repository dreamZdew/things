#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int n;
    vector<int> arr;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int t;
        scanf("%d", &t);
        arr.push_back(t);
    }
    vector<int> dp(n, 0);
    for (size_t i = 0; i < n; i++)
    {
        dp[i] = 1;
        for (size_t j = 0; j < i; j++)
        {
            if (arr[j] <= arr[i])
                dp[i] = max(dp[i], dp[j] + 1);
        }
    }
    cout << n - *max_element(dp.begin(), dp.end()) << endl;
}