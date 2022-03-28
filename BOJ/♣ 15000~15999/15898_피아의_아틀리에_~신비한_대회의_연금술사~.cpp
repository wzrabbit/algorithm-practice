#include <iostream>
#include <string>
#include <map>
using namespace std;

int power[10][4][4][4];
char color[11][5][5][5];
int powerPot[5][5];
char colorPot[6][6];
map<char, int> value;

void clearPot()
{
    for (int r = 0; r < 5; r++)
    {
        for (int c = 0; c < 5; c++)
        {
            powerPot[r][c] = 0;
            colorPot[r][c] = 'W';
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    value['W'] = 0;
    value['Y'] = 2;
    value['G'] = 3;
    value['B'] = 5;
    value['R'] = 7;

    int tc, x;
    char y;
    cin >> tc;

    for (int i = 0; i < tc; i++)
    {
        for (int r = 0; r < 4; r++)
        {
            for (int c = 0; c < 4; c++)
            {
                cin >> x;
                power[i][0][r][c] = x;
            }
        }
        for (int r = 0; r < 4; r++)
        {
            for (int c = 0; c < 4; c++)
            {
                cin >> y;
                color[i][0][r][c] = y;
            }
        }
    }

    for (int i = 0; i < tc; i++)
    {
        for (int j = 1; j < 4; j++)
        {
            for (int r = 0; r < 4; r++)
            {
                for (int c = 0; c < 4; c++)
                {
                    power[i][j][r][c] = power[i][j - 1][c][3 - r];
                    color[i][j][r][c] = color[i][j - 1][c][3 - r];
                }
            }
        }
    }

    // a, b, c: 세 재료 / d, e, f : 재료의 회전 방향 / ar, br, cr, ac, bc, cc : 재료를 넣는 위치 / ro, co : 행 열
    // 14중 for문 서커스
    int max_ = 0;

    for (int a = 0; a < tc; a++)
    {
        for (int b = 0; b < tc; b++)
        {
            if (a == b)
                continue;
            for (int c = 0; c < tc; c++)
            {
                if (a == c || b == c)
                    continue;
                for (int d = 0; d < 4; d++)
                {
                    for (int e = 0; e < 4; e++)
                    {
                        for (int f = 0; f < 4; f++)
                        {
                            for (int ar = 0; ar < 2; ar++)
                            {
                                for (int ac = 0; ac < 2; ac++)
                                {
                                    for (int br = 0; br < 2; br++)
                                    {
                                        for (int bc = 0; bc < 2; bc++)
                                        {
                                            for (int cr = 0; cr < 2; cr++)
                                            {
                                                for (int cc = 0; cc < 2; cc++)
                                                {
                                                    clearPot();

                                                    // 재료 1
                                                    for (int ro = 0; ro < 4; ro++)
                                                    {
                                                        for (int co = 0; co < 4; co++)
                                                        {
                                                            powerPot[ro + ar][co + ac] += power[a][d][ro][co];
                                                            if (powerPot[ro + ar][co + ac] < 0)
                                                                powerPot[ro + ar][co + ac] = 0;
                                                            else if (powerPot[ro + ar][co + ac] > 9)
                                                                powerPot[ro + ar][co + ac] = 9;

                                                            if (color[a][d][ro][co] != 'W')
                                                            {
                                                                colorPot[ro + ar][co + ac] = color[a][d][ro][co];
                                                            }
                                                        }
                                                    }

                                                    // 재료 2
                                                    for (int ro = 0; ro < 4; ro++)
                                                    {
                                                        for (int co = 0; co < 4; co++)
                                                        {
                                                            powerPot[ro + br][co + bc] += power[b][e][ro][co];
                                                            if (powerPot[ro + br][co + bc] < 0)
                                                                powerPot[ro + br][co + bc] = 0;
                                                            else if (powerPot[ro + br][co + bc] > 9)
                                                                powerPot[ro + br][co + bc] = 9;

                                                            if (color[b][e][ro][co] != 'W')
                                                            {
                                                                colorPot[ro + br][co + bc] = color[b][e][ro][co];
                                                            }
                                                        }
                                                    }

                                                    // 재료 3
                                                    for (int ro = 0; ro < 4; ro++)
                                                    {
                                                        for (int co = 0; co < 4; co++)
                                                        {
                                                            powerPot[ro + cr][co + cc] += power[c][f][ro][co];
                                                            if (powerPot[ro + cr][co + cc] < 0)
                                                                powerPot[ro + cr][co + cc] = 0;
                                                            else if (powerPot[ro + cr][co + cc] > 9)
                                                                powerPot[ro + cr][co + cc] = 9;

                                                            if (color[c][f][ro][co] != 'W')
                                                            {
                                                                colorPot[ro + cr][co + cc] = color[c][f][ro][co];
                                                            }
                                                        }
                                                    }

                                                    // 폭탄의 품질 계산
                                                    int current = 0;
                                                    for (int ro = 0; ro < 5; ro++)
                                                    {
                                                        for (int co = 0; co < 5; co++)
                                                        {
                                                            current += value[colorPot[ro][co]] * powerPot[ro][co];
                                                        }
                                                    }
                                                    if (current > max_)
                                                        max_ = current;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    cout << max_ << '\n';
}