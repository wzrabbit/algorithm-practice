#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

struct Query {
    int r, c;
};

vector<Query> queries;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int T;
    cin >> T;

    while (T--) {
        int R, C;
        cin >> R >> C;

        queries.clear();

        for (int r = 1; r <= R - 1; r++) {
            for (int c = 1; c <= C - 1; c++) {
                queries.push_back({r, c});
            }
        }

        for (int r = 2; r < R; r += 2) {
            queries.push_back({r, C});
        }

        for (int c = 2; c < C; c += 2) {
            queries.push_back({R, c});
        }

        if (R % 2 == 0 && C % 2 == 0) {
            queries.push_back({R, C});
        }

        cout << queries.size() << '\n';

        for (Query query : queries) {
            cout << query.r << ' ' << query.c << '\n';
        }
    }
}
