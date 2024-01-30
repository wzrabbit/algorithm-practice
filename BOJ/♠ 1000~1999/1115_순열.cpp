#include <iostream>
using namespace std;

int arr[50];
bool visited[50];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    int cycle_count = 0;

    for (int i = 0; i < N; i++) {
        if (visited[i]) {
            continue;
        }

        cycle_count += 1;
        int pos = i;

        while (!visited[pos]) {
            visited[pos] = true;
            pos = arr[pos];
        }
    }

    if (cycle_count == 1) {
        cout << 0;
    } else {
        cout << cycle_count;
    }
}