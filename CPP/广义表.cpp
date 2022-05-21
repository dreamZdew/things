#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef enum
{
    ATOM,
    LIST
} ElemTag;
struct GLNode
{
    ElemTag tag;
    union
    {
        char atom;
        struct ptr
        {
            struct GLNode *hp, *tp;
        };
    };
};
void subs();
void createG(GLNode *&L, char *S)
{
    if (strlen(S) == 0)
        L = NULL;
    else
    {
        L = (GLNode *)malloc(sizeof(GLNode));
        if (strlen(S) == 1)
        {
            L->tag = ATOM;
            L->atom = *S;
        }
        else
        {
            L->tag = LIST;
            GLNode *p = L;
        }
    }
}

