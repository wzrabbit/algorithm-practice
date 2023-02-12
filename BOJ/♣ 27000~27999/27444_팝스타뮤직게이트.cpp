#include <algorithm>
#include <iostream>
#include <cassert>
#define EMPTY 0
#define SINGLE 1
#define LONG 2
using namespace std;

int game[288002][9];
int _, X, N;
int score = 0;

void traverse_lane(int line_no) {
    int mode = EMPTY;
    int combo = 0;

    for (int r = N; r >= 0; r--) {
        if (game[r][line_no] == 0) {
            if (mode == SINGLE) score += combo * 100;
            if (mode == LONG) score += combo * X / 6;
            mode = EMPTY;
            combo = 0;
        }
        
        if (game[r][line_no] == 1) {
            if (mode == EMPTY) mode = SINGLE;
            combo += 1;
        }
        
        if (game[r][line_no] == 2) {
            if (combo == 0 && (r != N || game[r - 1][line_no] != 0)) score += 80;
            mode = LONG;
            combo += 1;
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> _ >> X >> N;

    for (int r = 1; r <= N; r++) {
        for (int c = 0; c < 9; c++) {
            cin >> game[r][c];
        }
    }
    
    for (int i = 0; i < 9; i++) {
        traverse_lane(i);
    }
    
    cout << score;
}