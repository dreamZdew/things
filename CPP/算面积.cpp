#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    cout << "选择图形类型，圆形输入1，长方形输入2，正方形输入3：";
    int n;
    cin >> n;
    if (n == 1)
    {
        cout << "输入半径：";
        double r;
        cin >> r;
        cout << "面积是：";
        cout << setiosflags(ios::fixed) << setprecision(2) << 3.141 * r * r << endl;
    }
    if (n == 2)
    {
        cout << "输入长和宽，以空格隔开：";
        double length, width;
        cin >> length >> width;
        cout << "面积是：";
        cout << setiosflags(ios::fixed) << setprecision(2) << length * width << endl;
    }
    if (n == 3)
    {
        cout << "输入边长：";
        double length;
        cin >> length;
        cout << "面积是：";
        cout << setiosflags(ios::fixed) << setprecision(2) << length * length << endl;
    }
}
