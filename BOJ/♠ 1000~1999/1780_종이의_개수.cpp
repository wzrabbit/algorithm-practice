#include <iostream>
using namespace std;

int paper[2188][2188];
struct res
{
    int m, z, o;
};

res traverse_paper(int row, int col, int scale)
{
    int first = paper[row][col];
    bool is_same = true;
    for (int r = row; r < row + scale; r++)
    {
        bool kill = false;
        for (int c = col; c < col + scale; c++)
        {
            if (paper[r][c] != first)
            {
                kill = true;
                is_same = false;
                break;
            }
        }
        if (kill)
            break;
    }

    if (is_same)
    {
        if (first == -1)
            return {1, 0, 0};
        else if (first == 0)
            return {0, 1, 0};
        else
            return {0, 0, 1};
    }
    else
    {
        res result = {0, 0, 0};
        for (int r = row; r < row + scale; r += scale / 3)
        {
            for (int c = col; c < col + scale; c += scale / 3)
            {
                res next = traverse_paper(r, c, scale / 3);
                result.m += next.m;
                result.z += next.z;
                result.o += next.o;
            }
        }
        return result;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    for (int r = 1; r <= n; r++)
    {
        for (int c = 1; c <= n; c++)
        {
            cin >> paper[r][c];
        }
    }

    res result = traverse_paper(1, 1, n);
    cout << result.m << '\n'
         << result.z << '\n'
         << result.o;
}