#include <iostream>
using namespace std;

int arr[100];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N, X;
    cin >> N >> X;

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    int index = 0;

    while (true) {
        if (arr[index] < X) {
            cout << index + 1;
            return 0;
        }

        index = (index + 1) % N;
        X += 1;
    }
}