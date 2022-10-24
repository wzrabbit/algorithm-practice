#include <algorithm>
#include <iostream>
using namespace std;

struct Room {
    int x, y, h;
};

Room room[1001];
int strength[1001];

int get_dist(int a, int b) {
    Room room_a = room[a];
    Room room_b = room[b];
    return abs(room_a.x - room_b.x) + abs(room_a.y - room_b.y);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N;
    cin >> N;

    for (int i = 0; i <= N; i++) {
        int x, y, h;
        cin >> x >> y >> h;
        room[i] = {x, y, h};
    }

    for (int i = 1; i <= N; i++) {
        strength[i] = max(0, room[0].h - get_dist(0, i));
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            int dist = get_dist(i, j);
            int hotspot = room[j].h;
            strength[i] = max(0, strength[i] - max(0, (hotspot - dist)));
        }
    }

    int best = 0;
    for (int i = 1; i <= N; i++) {
        best = max(best, strength[i]);
    }

    if (best > 0)
        cout << best;
    else
        cout << "IMPOSSIBLE";
}