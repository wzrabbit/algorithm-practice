#include <algorithm>
#include <iostream>
#include <vector>
typedef long long ll;
using namespace std;

struct ColorData {
    ll r, g, b;
};

char clipboard[52][52];
char canvas[112][112];
ColorData colors_count[112];
ll R, C, T, loop;

void make_color_counts() {
    for (int i = 1; i <= loop; i++) {
        for (int r = 1; r <= R; r++) {
            for (int c = 1; c <= C; c++) {
                char &old = canvas[r + i - 1][c + i - 1];
                char cur = clipboard[r][c];

                if (cur == '.') {
                    continue;
                }

                if (old == 'R') {
                    colors_count[i].r -= 1;
                } else if (old == 'G') {
                    colors_count[i].g -= 1;
                } else if (old == 'B') {
                    colors_count[i].b -= 1;
                }

                if (cur == 'R') {
                    colors_count[i].r += 1;
                } else if (cur == 'G') {
                    colors_count[i].g += 1;
                } else if (cur == 'B') {
                    colors_count[i].b += 1;
                }

                if (cur != '.') {
                    old = cur;
                }
            }
        }
    }
}

void print_answer() {
    ColorData total = {0, 0, 0};

    for (int i = 1; i <= min(T, loop); i++) {
        total.r += colors_count[i].r;
        total.g += colors_count[i].g;
        total.b += colors_count[i].b;
    }

    ll rest_loop = T - min(T, loop);

    total.r += colors_count[loop].r * rest_loop;
    total.g += colors_count[loop].g * rest_loop;
    total.b += colors_count[loop].b * rest_loop;

    cout << total.r << '\n'
         << total.g << '\n'
         << total.b;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> R >> C >> T;

    for (int r = 1; r <= R; r++) {
        cin >> (clipboard[r] + 1);
    }

    loop = min(R, C) + 1;

    make_color_counts();
    print_answer();
}
