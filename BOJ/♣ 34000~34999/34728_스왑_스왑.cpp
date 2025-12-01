#include <algorithm>
#include <iostream>
using namespace std;

int arr[10001];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N;
    cin >> N;

    int inversion_count = 0;

    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }

    for (int i = 1; i <= N - 1; i++) {
        for (int j = i + 1; j <= N; j++) {
            if (arr[i] > arr[j]) inversion_count += 1;
        }
    }

    if (inversion_count % 2 == 0) {
        cout << "Yes";
    } else {
        cout << "No";
    }
}
