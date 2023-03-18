#include <iostream>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int W, H, ant_W, ant_H, time;
    cin >> W >> H >> ant_W >> ant_H >> time;

    int W_moved = time % (W * 2);
    int H_moved = time % (H * 2);
    int direction = 1;

    for (int i = 0; i < W_moved; i++) {
        if (ant_W == W && direction == 1) {
            direction = -1;
        }

        if (ant_W == 0 && direction == -1) {
            direction = 1;
        }

        ant_W += direction;
    }

    direction = 1;
    for (int i = 0; i < H_moved; i++) {
        if (ant_H == H && direction == 1) {
            direction = -1;
        }

        if (ant_H == 0 && direction == -1) {
            direction = 1;
        }

        ant_H += direction;
    }

    cout << ant_W << ' ' << ant_H;
}