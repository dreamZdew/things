#include <iostream>
#include <random>
using namespace std;
int main()
{
    random_device rd;
    mt19937 eng(rd());
    uniform_int_distribution<int> dis(0, 2);
    int n;
    cout << "请出拳：" << endl
         << "石头输入1，剪刀输入2，布输入3：";
    while (cin >> n)
    {
        if (n != 1 && n != 2 && n != 3)
        {
            cout << "输入错误！" << endl;
            continue;
        }
        int computer;
        computer = dis(eng); //获取0~2的随机数
        cout << "你出了：";
        if (n == 1)
            cout << "石头" << endl;
        if (n == 2)
            cout << "剪刀" << endl;
        if (n == 3)
            cout << "布" << endl;
        cout << "电脑出了：";
        if (computer == 0)
            cout << "石头" << endl;
        if (computer == 1)
            cout << "剪刀" << endl;
        if (computer == 2)
            cout << "布" << endl;
        if (n - 1 == computer)
        {
            cout << "平局！" << endl;
            continue;
        }
        if ((n == computer) || (n == 3 && computer == 0))
        {
            cout << "你赢了！" << endl;
            continue;
        }
        else
        {
            cout << "你输了！" << endl;
            continue;
        }
    }
}