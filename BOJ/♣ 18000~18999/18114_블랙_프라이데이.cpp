#include <algorithm>
#include <iostream>
using namespace std;

int goods[5002];
int N, C;

bool has_valid_match(int start_index, int two_elements_sum) {
    int goal = C - two_elements_sum;
    int start = start_index;
    int end = N + 1;
    int mid;

    while (start <= end) {
        mid = (start + end) / 2;

        if (goods[mid] > goal) {
            end = mid - 1;
        } else if (goods[mid] < goal) {
            start = mid + 1;
        } else {
            return true;
        }
    }

    return false;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N >> C;

    for (int i = 0; i < N; i++) {
        cin >> goods[i];
    }

    sort(goods, goods + N + 2);

    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N + 1; j++) {
            if (has_valid_match(j + 1, goods[i] + goods[j])) {
                cout << 1;
                return 0;
            }
        }
    }

    cout << 0;
}