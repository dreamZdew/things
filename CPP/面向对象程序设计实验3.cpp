#include <iostream>
using namespace std;
class CPU
{
public:
    void run()
    {
        cout << "CPU开始运行" << endl;
    }
    void stop()
    {
        cout << "CPU停止运行" << endl;
    }
    void set(int a, float b);
    void display();
    enum CPU_Rank
    {
        P1 = 1,
        P2,
        P3,
        P4,
        P5,
        P6,
        P7
    };
private:
    int frequency;
    double voltage;
};
void CPU::set(int a, float b)
{
    frequency = a;
    voltage = b;
}
void CPU::display()
{
    cout << frequency << "MHz" << endl
         << voltage << "V" << endl
         << P1 << "," << P2 << "," << P3 << "," << P4 << "," << P5 << "," << P6 << "," << P7 << endl;
}
class CDROM
{
public:
    void run()
    {
        cout << "CDROM开始运行" << endl;
    }
    void stop()
    {
        cout << "CDROM停止运行" << endl;
    }
};
class RAM
{
public:
    void run()
    {
        cout << "RAM开始运行" << endl;
    }
    void stop()
    {
        cout << "RAM停止运行" << endl;
    }
};
class Computer
{
public:
    void run()
    {
        cout << "Computer开始运行" << endl;
    }
    void stop()
    {
        cout << "Computer停止运行" << endl;
    }
    CPU cpu;
    RAM ram;
    CDROM cdrom;
};
int main()
{
    Computer pc1;
    pc1.run();
    pc1.cpu.set(100, 12.25);
    pc1.cpu.display();
    pc1.ram.stop();
}
