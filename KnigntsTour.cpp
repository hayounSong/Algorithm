#include <iostream>

using namespace std;

#define MARK 1
#define UNMARK 0
typedef struct Point
{
    int x, y;
} point;

point direction[8] = {{1, -2}, {2, -1}, {2, 1}, {1, 2}, {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}};

int board[9][9], path[9][9];

int knightTour(int m, int n, point pos, int counter)
{
    int i;
    point next;

    if (counter == m * n)
    {
        return 1;
    }

    for (i = 0; i < 8; i++)
    {
        next.x = pos.x + direction[i].x;
        next.y = pos.y + direction[i].y;

        if (next.x > 0 && next.x <= n && next.y > 0 && next.y <= m && board[next.y][next.x] != MARK)
        {
            board[next.y][next.x] = MARK;
            path[next.y][next.x] = counter + 1;

            if (knightTour(m, n, next, counter + 1))
            {

                return 1;
            }
            board[next.y][next.x] = UNMARK;
        }
    }
    return 0;
}

int main()
{
    int N;
    cin >> N;

    for (int c = 0; c < N; c++)
    {
        point start;
        int m, n;

        cin >> m;
        cin >> n;
        cin >> start.y;
        cin >> start.x;

        for (int d = 1; d <= m; d++)
        {
            for (int a = 1; a <= n; a++)
            {
                board[d][a] = UNMARK;
            }
        }

        board[start.y][start.x] = MARK;
        path[start.y][start.x] = 1;

        if (knightTour(m, n, start, 1))
        {
            cout << 1 << "\n";
            for (int q = 1; q <= m; q++)
            {
                for (int w = 1; w <= n; w++)
                {
                    cout << path[q][w] << " ";
                }
                cout << "\n";
            }
        }
        else
        {
            cout << 0 << "\n";
        }
    }
}