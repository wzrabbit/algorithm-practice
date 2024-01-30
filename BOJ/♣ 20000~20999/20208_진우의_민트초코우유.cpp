#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

struct Pos {
    int r, c;
};

int grid[11][11];
int dist[11][11];
vector<Pos> milk_positions;
vector<int> permutation;
Pos start_position;
int N, start_hp, gain_hp;
int milk_count = 0;
int max_deliver_count = 0;

int get_dist(Pos a, Pos b) {
    return abs(a.r - b.r) + abs(a.c - b.c);
}

void make_dist_infos() {
    for (int c = 0; c < milk_count; c++) {
        int cur_dist = get_dist(start_position, milk_positions[c]);

        dist[0][c + 1] = cur_dist;
        dist[c + 1][0] = cur_dist;
    }

    for (int r = 0; r < milk_count; r++) {
        for (int c = 0; c < milk_count; c++) {
            int cur_dist = get_dist(milk_positions[r], milk_positions[c]);

            dist[r + 1][c + 1] = cur_dist;
            dist[c + 1][r + 1] = cur_dist;
        }
    }
}

void deliver(vector<int> order) {
    int hp = start_hp;
    int cur_position_no = 0;

    for (size_t i = 0; i < milk_count; i++) {
        int next_position_no = order[i];

        hp -= dist[cur_position_no][next_position_no];

        if (hp < 0) {
            return;
        }

        hp += gain_hp;

        if (hp <= 0) {
            return;
        }

        if (hp - dist[next_position_no][0] >= 0) {
            max_deliver_count = max(max_deliver_count, int(i + 1));
        }

        cur_position_no = next_position_no;
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N >> start_hp >> gain_hp;

    for (int r = 1; r <= N; r++) {
        for (int c = 1; c <= N; c++) {
            cin >> grid[r][c];

            if (grid[r][c] == 1) {
                start_position.r = r;
                start_position.c = c;
                continue;
            }

            if (grid[r][c] == 2) {
                milk_positions.push_back({r, c});
                milk_count += 1;
            }
        }
    }

    make_dist_infos();

    for (int i = 1; i <= milk_count; i++) {
        permutation.push_back(i);
    }

    do {
        deliver(permutation);
    } while (next_permutation(permutation.begin(), permutation.end()));

    cout << max_deliver_count;
}
