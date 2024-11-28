#include <algorithm>
#include <iostream>
#include <vector>
#define LEFT -1
#define RIGHT 0
using namespace std;

vector<int> base, trigger, pi;

int get_direction(int prev_x, int prev_y, int cur_x, int cur_y) {
    if (prev_x == cur_x) {
        return prev_y < cur_y ? 0 : 2;
    }

    return prev_x < cur_x ? 1 : 3;
}

void make_path(int line_count, vector<int>& target) {
    int prev_x, prev_y, prev_direction = -1;
    cin >> prev_x >> prev_y;

    for (int i = 1; i <= line_count - 1; i++) {
        int cur_x, cur_y;
        cin >> cur_x >> cur_y;

        int cur_direction = get_direction(prev_x, prev_y, cur_x, cur_y);

        if (prev_direction != -1 && cur_direction == (prev_direction + 1) % 4) {
            target.push_back(RIGHT);
        }

        if (prev_direction != -1 && cur_direction == (prev_direction + 3) % 4) {
            target.push_back(LEFT);
        }

        if (prev_x == cur_x) {
            target.push_back(abs(prev_y - cur_y));
        }

        if (prev_y == cur_y) {
            target.push_back(abs(prev_x - cur_x));
        }

        prev_x = cur_x;
        prev_y = cur_y;
        prev_direction = cur_direction;
    }
}

bool reverse_path(vector<int>& target) {
    vector<int> old_target(target.size());

    for (size_t i = 0; i < target.size(); i++) {
        old_target[i] = target[i];
    }

    reverse(target.begin(), target.end());

    for (size_t i = 0; i < target.size(); i++) {
        if (target[i] == LEFT) {
            target[i] = RIGHT;
        } else if (target[i] == RIGHT) {
            target[i] = LEFT;
        }
    }

    bool is_same = true;

    for (size_t i = 0; i < target.size(); i++) {
        if (old_target[i] != target[i]) {
            is_same = false;
            break;
        }
    }

    return !is_same;
}

void make_trigger_pi_array() {
    pi.resize(trigger.size() - 2);

    int l = 0;

    for (int r = 1; r < int(trigger.size()) - 2; r++) {
        while (l > 0 && trigger[l + 1] != trigger[r + 1]) {
            l = pi[l - 1];
        }

        if (trigger[l + 1] == trigger[r + 1]) {
            l += 1;
            pi[r] = l;
        }
    }
}

int get_matched_count() {
    int index = 1;
    int matched_count = 0;
    int T = trigger.size();
    int B = base.size();

    for (int i = 1; i < B - 1; i++) {
        while (index > 0 && base[i] != trigger[index + 1]) {
            index = pi[index - 1];
        }

        if (base[i] == trigger[index + 1]) {
            if (index < T - 3) {
                index += 1;
                continue;
            }

            int first_index = i - T + 2;
            int last_index = i + 1;

            if (
                base[first_index] >= trigger[0] &&
                base[last_index] >= trigger[T - 1]) {
                matched_count += 1;
            }

            index = pi[index];
        }
    }

    return matched_count;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N, M;
    cin >> N >> M;

    make_path(N, base);
    make_path(M, trigger);
    make_trigger_pi_array();

    int answer = 0;

    answer += get_matched_count();

    if (reverse_path(trigger)) {
        answer += get_matched_count();
    }

    cout << answer;
}
