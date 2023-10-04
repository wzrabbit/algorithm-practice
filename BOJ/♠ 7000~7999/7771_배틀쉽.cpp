#include <iostream>
#include <string>
using namespace std;

string boats[4] = {
    "####.###.#",
    "###.##.##.",
    "##.#.#....",
    ".........."};

int main() {
    int selected_row = -1;
    int selected_col = -1;
    int boat_index = 0;

    for (int r = 1; r <= 10; r++) {
        for (int c = 1; c <= 10; c++) {
            int cur;
            cin >> cur;

            if (cur == 100) {
                selected_row = r;
                selected_col = c;
            }
        }
    }

    bool is_odd = selected_row % 2 == 1;

    for (int r = 1; r <= 10; r++) {
        if (r == selected_row) {
            for (int c = 1; c <= 10; c++) {
                if (c == selected_col) {
                    cout << '#';
                } else {
                    cout << '.';
                }
            }

            cout << '\n';

            continue;
        }

        if (is_odd == r % 2) {
            cout << boats[boat_index++] << '\n';
        } else {
            cout << "..........\n";
        }
    }
}