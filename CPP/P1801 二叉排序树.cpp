#include <iostream>
using namespace std;
class BST
{
public:
    int value = 0;  //值
    int number = 0; //数量
    BST *lc = NULL, *rc = NULL;
};
void search(int v, BST T)
{
    if (T.value == v)
    {
        cout << endl;
        cout << T.number << endl;
    }
    if (v > T.value)
    {
        if (T.rc == NULL)
        {
            cout << endl;
            cout << 0 << endl;
            return;
        }
        cout << "->";
        search(v, *(T.rc));
    }
    if (v < T.value)
    {
        if (T.lc == NULL)
        {
            cout << endl;
            cout << 0 << endl;
            return;
        }
        cout << "<-";
        search(v, *(T.lc));
    }
}
void input(int v, BST &T)
{
    if (T.lc == NULL)
        T.lc = new BST;
    if (T.rc == NULL)
        T.rc = new BST;
    if (T.value == 0)
    {
        T.value = v;
        T.number++;
    }
    else
    {
        if (T.value == v)
            T.number++;
        if (v > T.value)
        {
            cout << "->";
            input(v, *(T.rc));
        }
        if (v < T.value)
        {
            cout << "<-";
            input(v, *(T.lc));
        }
    }
}
int main()
{
    BST *T = new BST;
    int n;
    cin >> n;
    while (n--)
    {
        int opt, x;
        cin >> opt >> x;
        if (opt == 1)
        {
            input(x, *T);
            cout << endl;
        }
        if (opt == 2)
        {
            search(x, *T);
        }
    }
}