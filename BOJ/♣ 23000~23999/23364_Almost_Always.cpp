#include <algorithm>
#include <iostream>
using namespace std;

int arr[500001];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N;
    cin >> N;

    int min_value = 2'000'000'000;
    int min_index = 0;

    for (int i = 1; i <= N; i++) {
        cin >> arr[i];

        if (arr[i] < min_value) {
            min_value = arr[i];
            min_index = i;
        }
    }

    for (int i = 1; i <= N; i++) {
        if (i == min_index) continue;

        if (arr[i] % arr[min_index] == 0) {
            cout << min_index << ' ' << i;
            break;
        }
    }
}