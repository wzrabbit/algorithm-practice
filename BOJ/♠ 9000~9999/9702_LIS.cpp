#include <algorithm>
#include <iostream>
#define INF 567
using namespace std;

int arr[501];
int previous[501];
int total_lis = 0;
int N;

int get_index(int value) {
    int start = 0;
    int end = N - 1;
    int mid;

    while (start <= end) {
        mid = (start + end) / 2;
        if (value > previous[mid]) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }

    return end;
}

void calculate_lis(int start_index, int end_index) {
    int lis = 0;
    fill(previous + 1, previous + N + 1, INF);

    for (int i = start_index; i <= end_index; i++) {
        int index = get_index(arr[i]) + 1;

        lis = max(lis, index);
        total_lis += lis;
        previous[index] = min(previous[index], arr[i]);
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int T;
    cin >> T;

    for (int t = 1; t <= T; t++) {
        cin >> N;
        total_lis = 0;

        for (int i = 1; i <= N; i++) {
            cin >> arr[i];
        }

        for (int i = 1; i <= N; i++) {
            calculate_lis(i, N);
        }

        cout << "Case #" << t << ": " << total_lis << '\n';
    }
}