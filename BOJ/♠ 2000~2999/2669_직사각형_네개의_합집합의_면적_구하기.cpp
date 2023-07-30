#include <iostream>
using namespace std;

bool is_filled[100][100];

int main() {
    for (int i = 1; i <= 4; i++) {
        int start_r, start_c, end_r, end_c;
        cin >> start_r >> start_c >> end_r >> end_c;

        for (int r = start_r; r < end_r; r++) {
            for (int c = start_c; c < end_c; c++) {
                is_filled[r][c] = true;
            }
        }
    }

    int area = 0;

    for (int r = 0; r < 100; r++) {
        for (int c = 0; c < 100; c++) {
            if (is_filled[r][c]) {
                area += 1;
            }
        }
    }

    cout << area;
}