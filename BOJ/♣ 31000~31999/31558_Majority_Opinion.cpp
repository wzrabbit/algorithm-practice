#include <iostream>
#include <set>
using namespace std;

int arr[100001];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        for (int i = 1; i <= N; i++) {
            cin >> arr[i];
        }

        set<int> answer;

        for (int i = 1; i <= 2; i++) {
            for (int j = 1; j <= N - i; j++) {
                if (arr[j] == arr[j + i]) {
                    answer.insert(arr[j]);
                }
            }
        }

        if (answer.empty()) {
            cout << -1 << '\n';
            continue;
        }

        for (auto it = answer.begin(); it != answer.end(); it++) {
            cout << *it << ' ';
        }

        cout << '\n';
    }
}
