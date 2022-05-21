#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct line
{
    char text[200];
    int num;
    struct line *next;
    struct line *pre;
};
void input();
void del();
void load();
void print();
struct line *begin;
struct line *end;
int main()
{

    load();
    print();
    printf("\n1、插入一行\n2、删除一行\n");
    for (;;)
    {
        int n;
        scanf("%d", &n);
        switch (n)
        {
        case 1:
            input();
            break;
        case 2:
            del();
            break;
        default:
            printf("无效输入！\n");
            continue;
        }
        print();
    }
}
void input()
{
    printf("请选择要插入的行号：\n");
    int n;
    scanf("%d", &n);
    struct line *info, *p;
    info = (struct line *)malloc(sizeof(struct line));
    p = begin;
    while (p->num != n)
        p = p->next;
    scanf("%s", info->text);
    info->text[strlen(begin->text)] = '\0';
    info->num = p->num;
    if (p == begin)
    {
        info->next = begin;
        begin->pre = info;
        begin = info;
        info->pre = NULL;
    }
    else if (p == end)
    {
        end->next = info;
        info->next = NULL;
        info->pre = end;
        end = info;
        p = p->next;
    }
    else
    {
        info->next = p;
        info->pre = p->pre;
        p->pre = info;
        info->pre->next = info;
    }
    while (p)
    {
        p->num = p->num + 1;
        p = p->next;
    }
}
void del()
{
    printf("请选择要删除的行号：\n");
    int n;
    scanf("%d", &n);
    struct line *info, *p;
    info = begin;
    while (info->num != n)
        info = info->next;
    p = info->next;
    if (info == begin)
    {
        begin = begin->next;
        if (begin == NULL)
            exit(0);
        begin->pre = NULL;
    }
    else
    {
        info->pre->next = info->next;
        if (info != end)
            info->next->pre = info->pre;
        else
            end = info->pre;
    }
    while (p)
    {
        p->num = p->num - 1;
        p = p->next;
    }
}
void load()
{
    begin = (struct line *)malloc(sizeof(struct line));
    end = (struct line *)malloc(sizeof(struct line));
    begin->next = (struct line *)malloc(sizeof(struct line));
    begin->num = 1;
    strcpy(begin->text, "中国，以华夏文明为源泉、中华文化为基础，是世界上历史最悠久的国家之一。");
    begin->next->num = 2;
    begin->next->pre = begin;
    begin->pre = NULL;
    strcpy(begin->next->text, "中国各族人民共同创造了光辉灿烂的文化，具有光荣的革命传统。");
    begin->next->next = end;
    end->pre = begin->next;
    end->next = NULL;
    strcpy(end->text, "中国是以汉族为主体民族的多民族国家，通用汉语、汉字，汉族与少数民族统称为“中华民族”，又自称“炎黄子孙”、“龙的传人”。");
    end->num = 3;
}
void print()
{
    struct line *p;
    p = begin;
    while (p)
    {
        printf("%d %s\n", p->num, p->text);
        p = p->next;
    }
}