#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int perm[120][6];
int collected_star[1025];

void make_perm() {
    int perm_maker[6] = {0, 5, 4, 3, 2, 1};

    for (int i = 0; i < 120; i++) {
        next_permutation(&perm_maker[1], &perm_maker[6]);
        for (int j = 1; j <= 5; j++)
            perm[i][j] = perm_maker[j];
    }
}

int get_edge_no(int a, int b) {
    if (a > b) swap(a, b);

    switch (a * 10 + b) {
        case 12:
            return 1 << 0;
        case 13:
            return 1 << 1;
        case 14:
            return 1 << 2;
        case 15:
            return 1 << 3;
        case 23:
            return 1 << 4;
        case 24:
            return 1 << 5;
        case 25:
            return 1 << 6;
        case 34:
            return 1 << 7;
        case 35:
            return 1 << 8;
        case 45:
            return 1 << 9;
    }

    return 0;
}

void make_star(vector<pair<int, int>> &star) {
    int min_ = 9999;

    for (int i = 0; i < 120; i++) {
        int cur = 0;

        for (size_t j = 0; j < star.size(); j++) {
            cur |= get_edge_no(perm[i][star[j].first], perm[i][star[j].second]);
        }

        min_ = min(min_, cur);
    }

    collected_star[min_]++;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N, E;
    cin >> N;
    vector<pair<int, int>> cur_star;

    make_perm();

    for (int i = 0; i < N; i++) {
        cur_star.clear();
        cin >> E;

        for (int j = 0, s, e; j < E; j++) {
            cin >> s >> e;
            cur_star.push_back(make_pair(s, e));
        }

        make_star(cur_star);
    }

    int beautiful = 0;
    for (int i = 0; i < 1024; i++) {
        if (collected_star[i] == 1)
            beautiful++;
    }

    cout << beautiful;
}