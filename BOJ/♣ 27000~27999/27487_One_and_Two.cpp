#include <iostream>
using namespace std;

int arr[1001];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        int all_two_count = 0;
        int current_two_count = 0;
        int answer = -1;

        for (int i = 1; i <= N; i++) {
            cin >> arr[i];
            if (arr[i] == 2) all_two_count += 1;
        }

        for (int i = 1; i <= N; i++) {
            if (arr[i] == 2) current_two_count += 1;
            if (current_two_count * 2 == all_two_count) {
                answer = i;
                break;
            }
        }

        cout << answer << '\n';
    }
}