//（4）使用string类定义字符串对象，实现两个字符串的比较、复制、连接等操作。
#include <iostream>
#include <string>
using namespace std;
int main()
{
    string str1 = "hello";
    string str2 = "hehe";
    str2+=str1;
    cout<<str2;
}
