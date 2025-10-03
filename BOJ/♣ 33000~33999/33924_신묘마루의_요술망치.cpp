#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

bool grid[5][3];

void perform_A() {
    swap(grid[1][1], grid[3][1]);
    swap(grid[1][2], grid[3][2]);
    swap(grid[2][1], grid[4][1]);
    swap(grid[2][2], grid[4][2]);
}

void perform_B() {
    swap(grid[1][1], grid[2][2]);
    swap(grid[1][2], grid[2][1]);
    swap(grid[3][1], grid[4][2]);
    swap(grid[3][2], grid[4][1]);
}

void perform_C() {
    swap(grid[1][1], grid[4][2]);
    swap(grid[1][2], grid[4][1]);
    swap(grid[2][1], grid[3][2]);
    swap(grid[2][2], grid[3][1]);
}

void perform_D() {
    int temp = grid[1][1];
    grid[1][1] = grid[2][1];
    grid[2][1] = grid[3][1];
    grid[3][1] = grid[4][1];
    grid[4][1] = grid[4][2];
    grid[4][2] = grid[3][2];
    grid[3][2] = grid[2][2];
    grid[2][2] = grid[1][2];
    grid[1][2] = temp;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int R, C, _;
    cin >> R >> C >> _;

    grid[R][C] = true;

    string S;
    cin >> S;

    for (size_t i = 0; i < S.size(); i++) {
        if (S[i] == 'A') perform_A();
        if (S[i] == 'B') perform_B();
        if (S[i] == 'C') perform_C();
        if (S[i] == 'D') perform_D();
    }

    for (int r = 1; r <= 4; r++) {
        for (int c = 1; c <= 2; c++) {
            if (grid[r][c]) {
                cout << r << ' ' << c;
                return 0;
            }
        }
    }
}
