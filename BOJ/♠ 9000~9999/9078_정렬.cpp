#include <iostream>
using namespace std;

int arr[101];
int N;

int get_parity(int target) {
    int result = 0;

    for (int i = target + 1; i <= N; i++) {
        if (arr[i] < arr[target]) {
            result += 1;
        }
    }

    return result;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int T;
    cin >> T;

    while (T--) {
        cin >> N;

        int parity_sum = 0;

        for (int i = 1; i <= N; i++) {
            cin >> arr[i];
        }

        for (int i = 1; i <= N; i++) {
            parity_sum += get_parity(i);
        }

        if (parity_sum % 2 == 0) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}
