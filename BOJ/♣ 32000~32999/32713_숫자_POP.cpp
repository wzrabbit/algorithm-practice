#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int arr[5000];
int N, K;

void init_vec(vector<int> &vec, int target) {
    bool is_target = arr[0] == target;
    int combo = 1;

    for (int i = 1; i < N; i++) {
        bool is_cur_target = arr[i] == target;

        if (is_cur_target == is_target) {
            combo += 1;
            continue;
        }

        if (is_cur_target) {
            vec.push_back(-combo);
        } else {
            vec.push_back(combo);
        }

        combo = 1;
        is_target = !is_target;
    }

    if (is_target) {
        vec.push_back(combo);
    } else {
        vec.push_back(-combo);
    }
}

int get_max_length(int target) {
    vector<int> vec;
    init_vec(vec, target);

    int l = -1;
    int r = -1;
    int max_length = 0;
    int cur_length = 0;
    int cost = 0;

    while (true) {
        if (cost <= K) {
            max_length = max(max_length, cur_length);

            r += 1;

            if (r == vec.size()) {
                break;
            }

            if (vec[r] > 0) {
                cur_length += vec[r];
            } else {
                cost -= vec[r];
            }

            continue;
        }

        l += 1;

        if (vec[l] > 0) {
            cur_length -= vec[l];
        } else {
            cost += vec[l];
        }
    }

    return max_length;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N >> K;

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    int max_length = 0;

    for (int i = 0; i < N; i++) {
        max_length = max(max_length, get_max_length(arr[i]));
    }

    cout << max_length;
}
