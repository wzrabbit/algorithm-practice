#include <iostream>
using namespace std;

int get_single_treasure_in_range(int start, int end) {
    int left = start;
    int right = end;
    int mid;

    while (left < right) {
        mid = (left + right) / 2;

        cout << "AK " << left << ' ' << mid << endl;

        char result;
        cin >> result;

        if (result == 'O') {
            right = mid;
        } else {
            left = mid + 1;
        }
    }

    return left;
}

void solve() {
    int N;
    cin >> N;

    int half = (N + 1) / 2;

    cout << "AK " << 1 << ' ' << half << endl;

    char result;
    cin >> result;

    if (result == 'O') {
        int left_treasure = get_single_treasure_in_range(1, half);
        int right_treasure = get_single_treasure_in_range(half + 1, N);
        cout << "! " << left_treasure << ' ' << right_treasure << endl;
        return;
    }

    for (int i = 2; i <= N - half; i++) {
        cout << "AK " << i << ' ' << i + half - 1 << endl;

        cin >> result;

        if (result == 'X') {
            continue;
        }

        int left_treasure, right_treasure;

        cout << "AK " << i - 1 << ' ' << i - 1 << endl;

        cin >> result;

        if (result == 'O') {
            left_treasure = i - 1;
            right_treasure = get_single_treasure_in_range(i, half);
        } else {
            left_treasure = i + half - 1;
            right_treasure = get_single_treasure_in_range(i + half, N);
        }

        cout << "! " << left_treasure << ' ' << right_treasure << endl;
        return;
    }

    cout << "! " << N - half << ' ' << N - half + 1 << endl;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int T;
    cin >> T;

    while (T--) {
        solve();
    }
}
