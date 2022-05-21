#include <iostream>
#include <vector>

using namespace std;

/*需要性能优化*/
/*也许list可以？*/

int findrightest2(vector<int> A) //找到数组最右侧的2的次方
{
    int m = 1;
    for (int i = 0; m <= A.size() - 1; i++)
        m *= 2;
    m /= 2;
    return m;
}

int findleftest2(vector<int> A, int k) //找到最左侧的，最靠近要删除的数的2的次方（是2的次方并且在第一个k左边）
{
    int left2po = 1;
    for (vector<int>::iterator it = A.begin() + 1; it != A.end(); it++)
    {
        if (*it == k)
        {
            for (; left2po < it - A.begin(); left2po *= 2)
                ;
            left2po /= 2;
            break;
        }
    }
    return left2po;
}

void erasein2(vector<int> A, int k, int &kcount, int &num) /*删除能放到2**n的*/
{
    int m = 0;
    m = findrightest2(A);
    while (true)
    {
        if (m < A.size() && A[m] == k)
        {
            num++;
            A.erase(A.begin() + m);
            kcount--;
            m = findrightest2(A);
        }
        else
            m /= 2;
        if (A.size() == 1 || (m == 1 && A[1] != k))
            break;
    }
}

int main()
{
    int n, k, num = 0, kcount = 0; // 1<=n<=300000
    cin >> n >> k;
    vector<int> A(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> A[i];
        if (A[i] == k)
            kcount++;
    }
    erasein2(A, k, kcount, num);

    for (vector<int>::iterator it = A.begin() + 1; kcount != 0; it = A.begin() + 1)
    {
        A.erase(it);
        num++;
        erasein2(A, k, kcount, num);
    }

    cout << num << endl;
}