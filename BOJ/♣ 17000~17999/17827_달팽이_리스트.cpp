#include <iostream>
using namespace std;

int arr[200001];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N, M, V;
    cin >> N >> M >> V;

    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }

    int cycle_size = N - V + 1;

    for (int i = 1; i <= M; i++) {
        int moves;
        cin >> moves;

        if (moves <= N - 1) {
            cout << arr[moves + 1] << '\n';
            continue;
        }

        cout << arr[(moves - N) % cycle_size + 1 + N - cycle_size] << '\n';
    }
}