#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

vector<string> piece;
vector<string> puzzle;
vector<bool> used(9);
int cnt = 0;

bool check_match(char a, char b)
{
    if (a < b)
        swap(a, b);

    if ((a == 'r' && b == 'R') || (a == 'g' && b == 'G') ||
        (a == 'b' && b == 'B') || (a == 'w' && b == 'W'))
        return true;
    else
        return false;
}

void rotate()
{
    puzzle[puzzle.size() - 1] =
        puzzle[puzzle.size() - 1].substr(1, 3) + puzzle[puzzle.size() - 1][0];
}

bool check_valid(int step)
{
    switch (step)
    {
    case 0:
        break;
    case 1:
        if (!check_match(puzzle[1][3], puzzle[0][1]))
            return false;
        break;
    case 2:
        if (!check_match(puzzle[2][3], puzzle[1][1]))
            return false;
        break;
    case 3:
        if (!check_match(puzzle[3][0], puzzle[0][2]))
            return false;
        break;
    case 4:
        if (!check_match(puzzle[4][0], puzzle[1][2]) ||
            !check_match(puzzle[4][3], puzzle[3][1]))
            return false;
        break;
    case 5:
        if (!check_match(puzzle[5][0], puzzle[2][2]) ||
            !check_match(puzzle[5][3], puzzle[4][1]))
            return false;
        break;
    case 6:
        if (!check_match(puzzle[6][0], puzzle[3][2]))
            return false;
        break;
    case 7:
        if (!check_match(puzzle[7][0], puzzle[4][2]) ||
            !check_match(puzzle[7][3], puzzle[6][1]))
            return false;
        break;
    case 8:
        if (!check_match(puzzle[8][0], puzzle[5][2]) ||
            !check_match(puzzle[8][3], puzzle[7][1]))
            return false;
        break;
    }

    return true;
}

void solve_puzzle(int step, int cur)
{
    puzzle.push_back(piece[cur]);
    used[cur] = true;

    for (int i = 0; i < 4; i++)
    {
        if (check_valid(step))
        {
            if (step == 8)
                cnt++;
            else
            {
                for (int j = 0; j < 9; j++)
                {
                    if (!used[j])
                        solve_puzzle(step + 1, j);
                }
            }
        }

        rotate();
    }

    puzzle.pop_back();
    used[cur] = false;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    int T;
    cin >> T;
    string p;

    while (T--)
    {
        for (int i = 0; i < 9; i++)
        {
            cin >> p;
            piece.push_back(p);
        }

        cnt = 0;

        for (int i = 0; i < 9; i++)
            solve_puzzle(0, i);

        cout << cnt << '\n';
        piece.clear();
    }
}