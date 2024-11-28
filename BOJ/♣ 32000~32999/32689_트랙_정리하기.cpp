#include <algorithm>
#include <iostream>
typedef long long ll;
using namespace std;

struct Range {
    int s, e;
};

int parent[200001];
int trash[200001];
bool is_clean[200001];
Range ranges[200001];
int N, clean_count = 0, location = 1;
ll dist = 0;

int get_parent(int child) {
    if (parent[child] == child) {
        return child;
    }

    return parent[child] = get_parent(parent[child]);
}

int get_left_location(int target) {
    target = get_parent(target);
    int location = ranges[target].s - 1;

    if (location == 0) {
        location = N;
    }

    return location;
}

int get_right_location(int target) {
    target = get_parent(target);
    int location = ranges[target].e + 1;

    if (location == N + 1) {
        location = 1;
    }

    return location;
}

ll get_distance(int left, int right) {
    if (left <= right) {
        return right - left;
    }

    return N - left + right;
}

void merge(int target) {
    int left = (target - 1 >= 1) ? target - 1 : N;
    int right = (target + 1 <= N) ? target + 1 : 1;

    if (!is_clean[left] && !is_clean[right]) {
        return;
    }

    if (is_clean[left]) {
        left = get_parent(left);
        parent[target] = left;
        ranges[left].e += 1;

        if (ranges[left].e == N + 1) {
            ranges[left].e = 1;
        }
    }

    if (is_clean[right]) {
        right = get_parent(right);
        target = get_parent(target);
        parent[target] = right;
        ranges[right].s = ranges[target].s;
    }
}

void clean_location(int target, int amount) {
    trash[target] -= amount;

    if (trash[target] == 0) {
        clean_count += 1;
        is_clean[target] = true;
        merge(target);
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> trash[i];
        parent[i] = i;
        ranges[i] = {i, i};
    }

    for (int i = 1; i <= N; i++) {
        if (trash[i] == 0) {
            is_clean[i] = true;
            clean_count += 1;
            merge(i);
        }
    }

    while (clean_count < N) {
        int left_location = get_left_location(location);
        int right_location = get_right_location(location);

        if (left_location == right_location) {
            dist += get_distance(location, right_location);
            dist += (trash[right_location] - 1) * N;

            clean_location(right_location, trash[right_location]);

        } else {
            int matched = min(trash[left_location], trash[right_location]);
            clean_location(left_location, matched);
            clean_location(right_location, matched);

            dist += get_distance(location, right_location);
            dist +=
                (matched * 2 - 1) * get_distance(left_location, right_location);
            location = left_location;
        }

        if (trash[location] > 0) {
            location += 1;

            if (location == N + 1) {
                location = 1;
            }

            dist += 1;
        }
    }

    cout << dist;
}
