#include <iostream>
using namespace std;
char Maze[9][9];
int n = 8;
int H[] = { 0, 1, 0, -1 };
int V[] = { -1, 0, 1, 0 };
void display()
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
            cout << Maze[i][j];
        cout << endl;
    }
}
void DFS(int x, int y)
{
    if (x == n - 1 && y == n - 1)
    {
        Maze[x][y] = ' ';
        display();
        exit(0);
    }
    else
    {
        for (int k = 0; k < 4; k++)
            if (x >= 0 && x < n && y >= 0 && y < n && Maze[x][y] == 'O')
            {
                Maze[x][y] = ' ';
                DFS(x + V[k], y + H[k]);
                Maze[x][y] = 'O';
            }
    }
}
int main(int argc, char const* argv[])
{
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
            cin >> Maze[i][j];
    DFS(0, 0);
    return 0;
}
