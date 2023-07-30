#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

struct Taxi {
    int r, c;
};

int main() {
    cin.tie(0)->sync_with_stdio(0);

    vector<Taxi> taxi;

    int R, C;
    cin >> R >> C;

    for (int r = 1; r <= R; r++) {
        for (int c = 1; c <= C; c++) {
            int cur;
            cin >> cur;

            if (cur == 1) {
                taxi.push_back({r, c});
            }
        }
    }

    int dist = abs(taxi[0].r - taxi[1].r) + abs(taxi[0].c - taxi[1].c);

    cout << dist;
}