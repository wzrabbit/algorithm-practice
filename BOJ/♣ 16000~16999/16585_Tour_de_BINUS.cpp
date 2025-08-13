#include <iostream>
#include <string>
using namespace std;

int arr[101];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }

    int pos;
    string direction;
    cin >> pos >> direction;

    int total = 0;
    int zero_count = 0;

    if (direction == "right") {
        for (int i = pos; i <= N; i++) total += arr[i];
    } else {
        for (int i = pos; i >= 1; i--) total += arr[i];
    }

    cin >> pos >> direction;

    if (direction == "right") {
        for (int i = pos; i <= N; i++) {
            if (arr[i] == 0) zero_count += 1;
        }

    } else {
        for (int i = pos; i >= 1; i--) {
            if (arr[i] == 0) zero_count += 1;
        }
    }

    cout << total << ' ' << zero_count;
}
