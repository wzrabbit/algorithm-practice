#include <iostream>
#include <map>
using namespace std;

char grid[12][12];

int main() {
    int N, F;
    cin >> N >> F;

    map<char, char> flip_vertical, flip_horizontal;

    flip_vertical['d'] = 'q';
    flip_vertical['q'] = 'd';
    flip_vertical['b'] = 'p';
    flip_vertical['p'] = 'b';

    flip_horizontal['d'] = 'b';
    flip_horizontal['q'] = 'p';
    flip_horizontal['b'] = 'd';
    flip_horizontal['p'] = 'q';

    for (int r = 1; r <= N; r++) {
        cin >> (grid[r] + 1);
    }

    if (F == 1) {
        for (int r = 1; r <= N; r++) {
            for (int c = 1; c <= N; c++) {
                cout << flip_vertical[grid[r][c]];
            }

            cout << '\n';
        }
    } else {
        for (int r = 1; r <= N; r++) {
            for (int c = 1; c <= N; c++) {
                cout << flip_horizontal[grid[r][c]];
            }

            cout << '\n';
        }
    }
}