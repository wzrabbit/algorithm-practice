#include <iostream>
using namespace std;

int main() {
    int K, N;
    cin >> K >> N;

    if (N == 1) {
        cout << -1;
        return 0;
    }

    if (K % (N - 1) == 0) {
        cout << K + K / (N - 1);
    } else {
        cout << K + K / (N - 1) + 1;
    }
}