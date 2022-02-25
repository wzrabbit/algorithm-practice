#include <iostream>
#include <algorithm>
using namespace std;

char dungeon[1501][1501];
int path[1501][1501] = {};
int top[1501][1501] = {};
int bottom[1501][1501] = {};
int obstacle[1501][1501] = {};
int dir, r_, c_;

// ←, ↓, →, ↑
int right_dr[4] = {0, 1, 0, -1};
int right_dc[4] = {-1, 0, 1, 0};

// ↑, →, ↓, ←
int left_dr[4] = {-1, 0, 1, 0};
int left_dc[4] = {0, 1, 0, -1};

void turn_normal()
{
    if (dir == 3)
        dir = 0;
    else
        dir++;
}

void turn_opposite()
{
    if (dir == 0)
        dir = 3;
    else
        dir--;
}

int check_square(int row, int col, int width)
{
    int to = top[row + width - 1][col + width - 1];
    if (row != 0)
        to -= top[row - 1][col + width - 1];
    if (col != 0)
        to -= top[row + width - 1][col - 1];
    if (row != 0 && col != 0)
        to += top[row - 1][col - 1];

    int bo = bottom[row + width - 1][col + width - 1];
    if (row != 0)
        bo -= bottom[row - 1][col + width - 1];
    if (col != 0)
        bo -= bottom[row + width - 1][col - 1];
    if (row != 0 && col != 0)
        bo += bottom[row - 1][col - 1];

    int ob = obstacle[row + width - 1][col + width - 1];
    if (row != 0)
        ob -= obstacle[row - 1][col + width - 1];
    if (col != 0)
        ob -= obstacle[row + width - 1][col - 1];
    if (row != 0 && col != 0)
        ob += obstacle[row - 1][col - 1];

    if (ob >= 1)
        return -1; // 장애물에 막힘 -> 탐색 범위를 줄여야 함
    if (to >= 1 && bo >= 1)
        return 1; // 성공! -> 탐색 범위를 줄여 더 작은 범위에도 성공하는 지 확인
    else
        return 0; // 실패 -> 탐색 범위를 늘려야 함
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int row, col;
    cin >> col >> row;
    for (int r = 0; r < row; r++)
    {
        cin >> dungeon[r];
    }

    // 1단계 : 좌·우수법 경로 기록
    int ro = 0;
    int co = 0;
    dir = 1;
    while (ro != row - 1 || co != col - 1)
    {
        turn_opposite();
        while (true)
        {
            int r = ro + right_dr[dir];
            int c = co + right_dc[dir];
            if (r >= 0 && r < row && c >= 0 && c < col && dungeon[r][c] != '#')
            {
                ro = r;
                co = c;
                if (path[r][c] != 2)
                    path[r][c] += 2;
                break;
            }
            else
            {
                turn_normal();
            }
        }
    }

    ro = 0;
    co = 0;
    dir = 1;
    while (ro != row - 1 || co != col - 1)
    {
        turn_opposite();
        while (true)
        {
            int r = ro + left_dr[dir];
            int c = co + left_dc[dir];
            if (r >= 0 && r < row && c >= 0 && c < col && dungeon[r][c] != '#')
            {
                ro = r;
                co = c;
                if (path[r][c] == 0 || path[r][c] == 2)
                    path[r][c] += 1;
                break;
            }
            else
            {
                turn_normal();
            }
        }
    }

    // 2단계: 누적 합을 이용해 현재 상태 기록
    dungeon[0][0] = '#';
    dungeon[row - 1][col - 1] = '#';

    if (dungeon[0][0] == '#')
    {
        obstacle[0][0] = 1;
    }
    else
    {
        if (path[0][0] == 1 || path[0][0] == 3)
            top[0][0] = 1;
        if (path[0][0] == 2 || path[0][0] == 3)
            bottom[0][0] = 1;
    }

    for (int c = 1; c < col; c++)
    {
        if (dungeon[0][c] == '#')
        {
            obstacle[0][c] = 1;
        }
        else
        {
            if (path[0][c] == 1 || path[0][c] == 3)
                top[0][c] = 1;
            if (path[0][c] == 2 || path[0][c] == 3)
                bottom[0][c] = 1;
        }
        top[0][c] += top[0][c - 1];
        bottom[0][c] += bottom[0][c - 1];
        obstacle[0][c] += obstacle[0][c - 1];
    }

    for (int r = 1; r < row; r++)
    {
        if (dungeon[r][0] == '#')
        {
            obstacle[r][0] = 1;
        }
        else
        {
            if (path[r][0] == 1 || path[r][0] == 3)
                top[r][0] = 1;
            if (path[r][0] == 2 || path[r][0] == 3)
                bottom[r][0] = 1;
        }
        top[r][0] += top[r - 1][0];
        bottom[r][0] += bottom[r - 1][0];
        obstacle[r][0] += obstacle[r - 1][0];
    }

    for (int r = 1; r < row; r++)
    {
        for (int c = 1; c < col; c++)
        {
            if (dungeon[r][c] == '#')
            {
                obstacle[r][c] = 1;
            }
            else
            {
                if (path[r][c] == 1 || path[r][c] == 3)
                    top[r][c] = 1;
                if (path[r][c] == 2 || path[r][c] == 3)
                    bottom[r][c] = 1;
            }
            top[r][c] += top[r - 1][c] + top[r][c - 1] - top[r - 1][c - 1];
            bottom[r][c] += bottom[r - 1][c] + bottom[r][c - 1] - bottom[r - 1][c - 1];
            obstacle[r][c] += obstacle[r - 1][c] + obstacle[r][c - 1] - obstacle[r - 1][c - 1];
        }
    }

    // 3단계: 매개 변수 탐색을 이용해 각 좌표마다 적합한 장애물 크기 계산
    int final_ans = 9999;
    int final_row = 0;
    int final_col = 0;

    for (int r = 0; r < row; r++)
    {
        for (int c = 0; c < col; c++)
        {
            int start = 1;
            int end = min(row - r, col - c);
            int mid;

            while (start <= end)
            {
                mid = (start + end) / 2;
                int check_result = check_square(r, c, mid);
                if (check_result == 1)
                {
                    if (mid < final_ans)
                    {
                        final_ans = mid;
                        final_row = r + 1;
                        final_col = c + 1;
                    }
                    end = mid - 1;
                }
                else if (check_result == 0)
                    start = mid + 1;
                else
                    end = mid - 1;
            }
        }
    }

    if (final_ans == 9999)
        cout << "Impossible";
    else
        cout << final_ans << ' ' << final_col << ' ' << final_row;
}