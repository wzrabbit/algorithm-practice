#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

vector<int> dragon_curves;
int is_crossed[101][101];
int dr[4] = {0, -1, 0, 1};
int dc[4] = {1, 0, -1, 0};

void expand_curve() {
    int curve_size = dragon_curves.size();

    for (int i = curve_size - 1; i >= 0; i--) {
        dragon_curves.push_back((dragon_curves[i] + 1) % 4);
    }
}

void draw_curve(int start_r, int start_c) {
    int r = start_r;
    int c = start_c;
    is_crossed[r][c] = true;

    for (size_t i = 0; i < dragon_curves.size(); i++) {
        int direction = dragon_curves[i];

        r += dr[direction];
        c += dc[direction];
        is_crossed[r][c] = true;
    }
}

bool is_crossed_square(int start_r, int start_c) {
    return is_crossed[start_r][start_c] &&
           is_crossed[start_r + 1][start_c] &&
           is_crossed[start_r][start_c + 1] &&
           is_crossed[start_r + 1][start_c + 1];
}

int get_square_count() {
    int count = 0;

    for (int r = 0; r <= 99; r++) {
        for (int c = 0; c <= 99; c++) {
            if (is_crossed_square(r, c)) count += 1;
        }
    }

    return count;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N;
    cin >> N;

    while (N--) {
        int start_c, start_r, direction, level;
        cin >> start_c >> start_r >> direction >> level;

        dragon_curves.push_back(direction);

        for (int i = 0; i < level; i++) {
            expand_curve();
        }

        draw_curve(start_r, start_c);
    }

    cout << get_square_count();
}