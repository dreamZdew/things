#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct wordlist
{
    char item[20];
    int last;
};
struct booknumlist
{
    int num[3];
    struct booklist *next;
    struct booklist *begin;
};
struct keylist
{
    char key[20];
    int length;
    struct booknumlist booknum;
};
struct keylist keyl;
struct book
{
    int num;
    char name[100];
    struct book *next;
};
struct book *begin;
struct book *end;
void input();
void init();
void extract();
void extractwordfromstr(char a[]);
int main()
{
    void init();
}
void init()
{
    struct book books;
    begin->num = 005;
    strcpy(begin->name, "Computer Data Structures");
    begin->next->num = 010;
    strcpy(begin->next->name, "Introduction to Data Structures");
    end = begin->next->next;
    end->next = NULL;
    end->num = 023;
    strcpy(end->name, "Fundamentals of Data Structures");
}
void extract()
{
    struct book *p;
    p = begin;
    while (p)
    {

        p = p->next;
    }
}
void extractwordfromstr(char a[])
{
    char str[20];
    int i = 0;
    for (; i < strlen(a);)
    {
        for (; a[i] != ' '; i++)
        {
            str[i] = a[i];
        }
        strcpy(keyl.key,str);
    }
}
void input()
{
}
