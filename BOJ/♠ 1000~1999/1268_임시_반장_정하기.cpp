#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int grid[1001][6];
bool is_met[1001][1001];
vector<int> bundle[10];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N;
    cin >> N;

    for (int r = 1; r <= N; r++) {
        for (int c = 1; c <= 5; c++) {
            cin >> grid[r][c];
        }
    }

    for (int c = 1; c <= 5; c++) {
        for (int i = 1; i <= 9; i++) {
            bundle[i].clear();
        }

        for (int r = 1; r <= N; r++) {
            bundle[grid[r][c]].push_back(r);
        }

        for (int i = 1; i <= 9; i++) {
            for (size_t j = 0; j < bundle[i].size(); j++) {
                for (size_t k = 0; k < bundle[i].size(); k++) {
                    int me = bundle[i][j];
                    int bro = bundle[i][k];

                    is_met[me][bro] = true;
                }
            }
        }
    }

    int leader;
    int best_score = 0;

    for (int r = 1; r <= N; r++) {
        int cur_score = 0;

        for (int c = 1; c <= N; c++) {
            if (is_met[r][c]) {
                cur_score += 1;
            }
        }

        if (cur_score > best_score) {
            leader = r;
            best_score = cur_score;
        }
    }

    cout << leader;
}