#include <algorithm>
#include <iostream>
using namespace std;

int arr[10010];
int prefix[20010];
int N;

int find_next_node(int index, int side_length) {
    int start = 1;
    int end = N;
    int mid;

    while (start <= end) {
        mid = (start + end) / 2;

        int cur_side_length = prefix[index + mid] - prefix[index];

        if (cur_side_length == side_length) {
            if (index + mid <= N) {
                return index + mid;
            }

            return (index + mid) % N;
        }

        if (cur_side_length > side_length) {
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }

    return -1;
}

bool is_possible_by_start_node(int start_node, int side_length) {
    int cur_node = start_node;

    while (true) {
        cur_node = find_next_node(cur_node, side_length);

        if (cur_node == start_node) {
            return true;
        }

        if (cur_node == -1) {
            return false;
        }
    }
}

bool is_possible(int node_count) {
    if (prefix[N + 1] % node_count != 0) {
        return false;
    }

    int side_length = prefix[N + 1] / node_count;

    for (int i = 1; i <= N; i++) {
        if (is_possible_by_start_node(i, side_length)) {
            return true;
        }
    }

    return false;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    while (true) {
        cin >> N;

        if (N == 0) {
            break;
        }

        for (int i = 1; i <= N; i++) {
            cin >> arr[i];
        }

        for (int i = 2; i <= N * 2; i++) {
            prefix[i] = prefix[i - 1] + arr[(i - 2) % N + 1];
        }

        bool success = false;

        for (int i = N; i >= 3; i--) {
            if (is_possible(i)) {
                success = true;
                cout << N - i << '\n';
                break;
            }
        }

        if (!success) {
            cout << -1 << '\n';
        }
    }
}
