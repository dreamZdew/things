#include <iostream>
#include <cstring>
using namespace std;
class People
{
public:
    class date
    {
    public:
        void birth(int y, int m, int d)
        {
            year = y;
            month = m;
            day = d;
        }
        int getyear() { return year; }
        int getmonth() { return month; }
        int getday() { return day; }

        int year;
        int month;
        int day;
    };
    People();
    People(People &p);
    void set(char neme[], char a[], char b[], int y, int m, int d, char i[18]);
    void display();
    ~People() {}
    char name[11];
    char number[7];
    char sex[4];
    date birthday;
    char id[19];
};
People::People() : name("张三"), number("123456"), id("320101190001011919"), sex("男") //构造函数
{
    birthday.birth(1900, 1, 1);
}
People::People(People &p) //复制构造函数
{
    strcpy(name, p.name);
    strcpy(number, p.number);
    strcpy(sex, p.sex);
    birthday.birth(p.birthday.getyear(), p.birthday.getmonth(), p.birthday.getday());
    strcpy(id, p.id);
}
void People::set(char n[], char a[], char b[], int y, int m, int d, char i[18])
{
    strcpy(name, n);
    strcpy(number, a);
    strcpy(sex, b);
    birthday.birth(y, m, d);
    strcpy(id, i);
}
void People::display()
{
    cout << endl;
    cout << "编号：" << number << endl;
    cout << "姓名：" << name << endl;
    cout << "性别：" << sex << endl;
    cout << "生日：" << birthday.getyear() << "/" << birthday.getmonth() << "/" << birthday.getday() << endl;
    cout << "身份证号：" << id << endl;
    cout << endl;
}

/*（4）从实验5中的people（人员）类派生出student(学生)类，添加属性：班号char classNo[7]；
从people类派生出teacher（教师）类，添加属性：职务char principalship[11]、部门char department[21]。
从student类派生出graduate（研究生）类，添加属性：专业char subject[21]、导师teacher adviser；
从graduate类和teacher类派出TA（助教生）类，注意虚基类的使用。重载相应的成员函数，测试这些类。*/
class student : virtual public People
{
public:
    char classNo[7];
};
class teacher : virtual public People
{
public:
    teacher();
    char principalship[11];
    char department[21];
};
teacher::teacher() : principalship("博导"), department("高级部门")
{
}

class graduate : virtual public student
{
public:
    char subject[21];
    teacher adviser;
};
class TA : virtual public graduate, virtual public teacher
{
public:
    TA();
    void display();
};
TA::TA()
{
    strcpy(classNo, "2020(11)");
    strcpy(adviser.name, "王二");
    strcpy(subject, "CS");
    cout << "TA created" << endl;
}
void TA::display()
{
    cout << endl;
    cout << "编号：" << number << endl;
    cout << "姓名：" << name << endl;
    cout << "性别：" << sex << endl;
    cout << "生日：" << birthday.getyear() << "/" << birthday.getmonth() << "/" << birthday.getday() << endl;
    cout << "身份证号：" << id << endl;
    cout << "专业：" << subject << endl;
    cout << "班号：" << classNo << endl;
    cout << "导师：" << adviser.name << endl;
    cout << endl;
}

int main()
{
    People A;
    A.display();
    People B(A);
    B.display();
    People C;
    C.set("李四", "114514", "女", 1970, 10, 1, "320101198010012211");
    C.display();
    TA AAA;
    AAA.display();
}