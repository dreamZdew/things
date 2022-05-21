#include<iostream>
#include<chrono>
#include<string>
using namespace std;
int main()
{
    time_t now =time(0);
    tm *t=localtime(&now);
    char str[15];
    strftime(str,15,"%Y%m%d%H%M%S",t);
    string ordernumber=str;
    cout<<ordernumber<<endl;
}