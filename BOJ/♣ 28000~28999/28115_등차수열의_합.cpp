#include <iostream>
using namespace std;

int arr[100001];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }

    int gap = arr[2] - arr[1];
    bool success = true;

    for (int i = 3; i <= N; i++) {
        if (arr[i] - arr[i - 1] != gap) {
            success = false;
            break;
        }
    }

    if (success) {
        cout << "YES\n";

        for (int i = 1; i <= N; i++) {
            cout << arr[i] << ' ';
        }
        cout << '\n';

        for (int i = 1; i <= N; i++) {
            cout << 0 << ' ';
        }
        cout << '\n';
    } else {
        cout << "NO\n";
    }
}