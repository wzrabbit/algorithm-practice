#include <iostream>
using namespace std;

int arr[30002];
int answer[4];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }

    arr[N + 1] = arr[1];

    int previous = 0;

    for (int i = 1; i <= N; i++) {
        if (arr[i] == arr[i + 1] && previous != 1) {
            answer[previous] += 1;
            previous = 1;
        }

        if (arr[i] < arr[i + 1] && previous != 2) {
            answer[previous] += 1;
            previous = 2;
        }

        if (arr[i] > arr[i + 1] && previous != 3) {
            answer[previous] += 1;
            previous = 3;
        }
    }

    answer[previous] += 1;

    for (int i = 1; i <= 3; i++) {
        cout << answer[i] << ' ';
    }
}