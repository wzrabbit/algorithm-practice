#include <iostream>
#include <vector>
#define INF 987654
using namespace std;

int arr[100001];
int N;

bool is_possible(int interval) {
    int min_max_sum = -1;

    for (int i = 0; i < N / interval; i++) {
        int min_value = INF;
        int max_value = 0;

        for (int j = i * interval + 1; j <= (i + 1) * interval; j++) {
            min_value = min(min_value, arr[j]);
            max_value = max(max_value, arr[j]);
        }

        if (min_max_sum == -1) {
            min_max_sum = min_value + max_value;
            continue;
        }

        if (min_value + max_value != min_max_sum) {
            return false;
        }
    }

    return true;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }

    for (int i = 1; i < N; i++) {
        if (N % i == 0 && is_possible(i)) {
            cout << 1;
            return 0;
        }
    }

    cout << 0;
}
