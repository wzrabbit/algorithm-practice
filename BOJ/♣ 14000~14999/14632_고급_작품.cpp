#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Query {
    int n, r, c;
};

char canvas[1001][1001];
int parent[1001][1001];
vector<string> stamps[501];
Query queries[10000];
int R, C, K;

int get_parent(int row, int child) {
    if (parent[row][child] == 0) {
        return child;
    }

    return parent[row][child] = get_parent(row, parent[row][child]);
}

void merge(int row, int a, int b) {
    a = get_parent(row, a);
    b = get_parent(row, b);

    if (a != b) {
        parent[row][a] = b;
    }
}

void draw_stamp(int stamp_no, int start_r, int start_c) {
    int stamp_r = stamps[stamp_no].size();
    int stamp_c = stamps[stamp_no][0].size();

    for (int r = start_r; r < start_r + stamp_r; r++) {
        int c = start_c;

        while (true) {
            c = get_parent(r, c);

            if (c >= start_c + stamp_c) {
                break;
            }

            canvas[r][c] = stamps[stamp_no][r - start_r][c - start_c];
            merge(r, c, c + 1);
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> R >> C >> K;

    fill(&canvas[0][0], &canvas[R - 1][C], '.');

    for (int i = 1; i <= K; i++) {
        int stamp_r, stamp_c;
        cin >> stamp_r >> stamp_c;

        for (int r = 0; r < stamp_r; r++) {
            string cur_line;
            cin >> cur_line;

            stamps[i].push_back(cur_line);
        }
    }

    int Q;
    cin >> Q;

    for (int i = 0; i < Q; i++) {
        cin >> queries[i].n >> queries[i].r >> queries[i].c;
    }

    reverse(queries, queries + Q);

    for (int i = 0; i < Q; i++) {
        draw_stamp(queries[i].n, queries[i].r, queries[i].c);
    }

    for (int r = 0; r < R; r++) {
        for (int c = 0; c < C; c++) {
            cout << canvas[r][c];
        }
        cout << '\n';
    }
}
