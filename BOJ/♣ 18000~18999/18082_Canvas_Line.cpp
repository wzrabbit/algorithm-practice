#include <iostream>
#include <set>
#include <vector>
using namespace std;

struct Canvas {
    int l, r;
};

Canvas canvases[1001];
int attach_counts[1001];
set<int> attach_positions;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> canvases[i].l >> canvases[i].r;
    }

    int P;
    cin >> P;

    for (int i = 1; i <= P; i++) {
        int cur;
        cin >> cur;

        attach_positions.insert(cur);

        for (int j = 1; j <= N; j++) {
            if (canvases[j].l <= cur && cur <= canvases[j].r) {
                attach_counts[j] += 1;
            }
        }
    }

    vector<int> answer;

    for (int i = 1; i <= N; i++) {
        if (attach_counts[i] >= 3) {
            cout << "impossible";
            return 0;
        }

        if (i != N && canvases[i].r == canvases[i + 1].l &&
            attach_counts[i] < 2 && attach_counts[i + 1] < 2 &&
            attach_positions.find(canvases[i].r) == attach_positions.end()) {
            answer.push_back(canvases[i].r);
            attach_positions.insert(canvases[i].r);
            attach_counts[i] += 1;
            attach_counts[i + 1] += 1;
        }

        for (int j = canvases[i].l + 1; j < canvases[i].r; j++) {
            if (attach_counts[i] == 2) {
                break;
            }

            if (attach_positions.find(j) == attach_positions.end()) {
                attach_counts[i] += 1;
                answer.push_back(j);
                attach_positions.insert(j);
            }
        }
    }

    cout << answer.size() << '\n';

    for (int cur : answer) {
        cout << cur << ' ';
    }
}
