#include <iostream>
#include <set>
using namespace std;

int grid[2001][2001];
int best_no[2001];
int best_value[2001];
bool is_only[2001];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int R, C;
    cin >> R >> C;

    for (int r = 1; r <= R; r++) {
        for (int c = 1; c <= C; c++) {
            cin >> grid[r][c];
        }
    }

    for (int r = 1; r <= R; r++) {
        for (int c = 1; c <= C; c++) {
            if (grid[r][c] == best_value[c]) {
                is_only[c] = false;
            }

            if (grid[r][c] > best_value[c]) {
                is_only[c] = true;
                best_no[c] = r;
                best_value[c] = grid[r][c];
            }
        }
    }

    set<int> candidates;

    for (int i = 1; i <= C; i++) {
        if (is_only[i]) candidates.insert(best_no[i]);
    }

    cout << candidates.size();
}
