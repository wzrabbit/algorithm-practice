#include <algorithm>
#include <iostream>
using namespace std;

vector<int> sectors;

int main() {
    int N;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        int cur;
        cin >> cur;
        sectors.push_back(cur);
    }

    sort(sectors.begin(), sectors.end());

    int best_line_count = 0;

    do {
        vector<int> angles(50, 0);
        int cur_angle = 0;

        for (size_t i = 0; i < sectors.size(); i++) {
            cur_angle += sectors[i];
            angles[cur_angle % 50] += 1;
        }

        int cur_line_count = 0;

        for (int i = 0; i < 50; i++) {
            if (angles[i] == 2) {
                cur_line_count += 1;
            }
        }

        best_line_count = max(best_line_count, cur_line_count);
    } while (next_permutation(sectors.begin(), sectors.end()));

    cout << best_line_count;
}