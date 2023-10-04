#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

struct History {
    int t, x, y;
};

bool operator<(const History& a, const History& b) {
    return a.t < b.t;
}

vector<History> histories;
bool infect_result[101];
bool simulation[101];
int candidates = 0;
int N, T, K_min, K_max;

void simulate(int patient_zero) {
    if (!infect_result[patient_zero]) {
        return;
    }

    bool is_valid_patient_zero = false;

    for (int k = 0; k <= T; k++) {
        bool simulation[N + 1] = {};
        int virus_remain[N + 1] = {};

        simulation[patient_zero] = true;
        virus_remain[patient_zero] = k;

        for (int i = 0; i < T; i++) {
            History cur = histories[i];

            if (virus_remain[cur.x] > 0 || virus_remain[cur.y] > 0) {
                if (simulation[cur.x]) {
                    virus_remain[cur.x] -= 1;
                } else {
                    virus_remain[cur.x] = k;
                    simulation[cur.x] = true;
                }

                if (simulation[cur.y]) {
                    virus_remain[cur.y] -= 1;
                } else {
                    virus_remain[cur.y] = k;
                    simulation[cur.y] = true;
                }
            }
        }

        bool is_valid = true;

        for (int i = 1; i <= N; i++) {
            if (simulation[i] != infect_result[i]) {
                is_valid = false;
                break;
            }
        }

        if (is_valid) {
            is_valid_patient_zero = true;
            K_min = min(K_min, k);
            K_max = max(K_max, k);
        }
    }

    if (is_valid_patient_zero) {
        candidates += 1;
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N >> T;

    int patient_count = 0;
    K_min = T;
    K_max = 0;

    for (int i = 1; i <= N; i++) {
        char cur;
        cin >> cur;

        infect_result[i] = cur - '0';

        if (infect_result[i]) {
            patient_count += 1;
        }
    }

    for (int i = 1; i <= T; i++) {
        int t, x, y;
        cin >> t >> x >> y;

        histories.push_back({t, x, y});
    }

    sort(histories.begin(), histories.end());

    for (int i = 1; i <= N; i++) {
        simulate(i);
    }

    cout << candidates << ' ';

    if (K_min == T) {
        cout << "Infinity ";
    } else {
        cout << K_min << ' ';
    }

    if (K_max == T) {
        cout << "Infinity ";
    } else {
        cout << K_max << ' ';
    }
}