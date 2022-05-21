#include <iostream>
using namespace std;
/* （1）定义Point类，有坐标x，y两个整型成员变量。对Point类重载＋、－、++（前置）、--（后置）四种运算符，实现对坐标值的运算与改变。（分别重载为成员函数、非成员函数）
（2）对实验5中的People类，重载“= =”运算符和“=”运算符，“= =”运算符判断两个People类对象的id属性是否相等；“=”运算符实现People类对象的赋值操作。
（3）修改实验6中内容（3），给bicycle、motorcar、motorcycle这三个类均定义Run、Stop等成员函数，观察虚函数的作用。
 */
class vehicle
{
public:
    virtual void Run() { cout << "vehicle run" << endl; }
    void Stop() { cout << "vehicle stop" << endl; }
    int MaxSpeed;
    int Weight;
};
class bicycle : virtual public vehicle
{
public:
    void Run() { cout << "bicycle run" << endl; }
    void Stop() { cout << "bicycle run" << endl; }
    int Height;
};
class motorcar : virtual public vehicle
{
public:
    void Run() { cout << "motorcar run" << endl; }
    void Stop() { cout << "motorcar stop" << endl; }
    int SeatNum;
};
class motorcycle : virtual public bicycle, public motorcar
{
public:
    void Run() { cout << "motorcycle run" << endl; }
    void Stop() { cout << "motorcycle stop" << endl; }
};
int main()
{
    motorcycle A;
    motorcar B;
    vehicle *C[] = {&A, &B};
    for (size_t i = 0; i < 2; i++)
    {
        C[i]->Run();
    }
}
