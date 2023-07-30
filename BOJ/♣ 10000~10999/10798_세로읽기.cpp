#include <iostream>
using namespace std;

char grid[17][17];

int main() {
    for (int r = 1; r <= 5; r++) {
        cin >> (grid[r] + 1);
    }

    for (int c = 1; c <= 15; c++) {
        for (int r = 1; r <= 5; r++) {
            if (grid[r][c] != 0) {
                cout << grid[r][c];
            }
        }
    }
}