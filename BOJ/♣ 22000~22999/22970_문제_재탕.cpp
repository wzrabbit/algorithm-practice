#include <iostream>
using namespace std;

int arr[5001];
int N;

int get_mountain_size(int start_index) {
    int mountain_size = 1;

    for (int i = start_index; i >= 2; i--) {
        if (arr[i - 1] < arr[i]) {
            mountain_size += 1;
            continue;
        }
        break;
    }

    for (int i = start_index; i <= N - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            mountain_size += 1;
            continue;
        }
        break;
    }

    return mountain_size;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }

    int answer = 1;

    for (int i = 1; i <= N; i++) {
        answer = max(answer, get_mountain_size(i));
    }

    cout << answer;
}
