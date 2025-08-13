#include <algorithm>
#include <iostream>
using namespace std;

int arr[200001];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N, K;
    cin >> N >> K;

    int zero_count = 0;

    for (int i = 1; i <= N; i++) {
        cin >> arr[i];

        if (arr[i] == 0) {
            zero_count += 1;
        }
    }

    sort(arr + 1, arr + N + 1);

    int min_mex = min(N, arr[N] + 1);
    int max_mex = 0;
    int chance = K;

    if (zero_count <= K) {
        min_mex = 0;
    }

    int prev_element = -1;
    int current_element = arr[1];
    int element_count = 0;

    for (int i = 1; i <= N; i++) {
        if (current_element - prev_element >= 2) {
            min_mex = min(min_mex, prev_element + 1);
        }

        if (arr[i] == current_element) {
            element_count += 1;
            continue;
        }

        if (element_count <= K) {
            min_mex = min(min_mex, prev_element + 1);
        }

        prev_element = current_element;
        current_element = arr[i];
        element_count = 1;
    }

    if (element_count <= K) {
        min_mex = min(min_mex, prev_element + 1);
    }

    chance = K;

    for (int i = 1; i <= N; i++) {
        if (arr[i] < max_mex) {
            continue;
        }

        if (chance >= arr[i] - max_mex) {
            chance -= arr[i] - max_mex;
            max_mex = arr[i] + 1;
            continue;
        }

        max_mex += chance;
        chance = 0;
        break;
    }

    if (chance > 0) {
        max_mex += chance;
    }

    cout << min_mex << '\n' << max_mex;
}
