#include <iostream>
#include <vector>
using namespace std;

int arr[5001];
vector<int> queries;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }

    int progress = 1;

    while (true) {
        for (int i = progress; i <= N; i++) {
            if (arr[i] == i) {
                progress += 1;
                continue;
            }

            break;
        }

        if (progress == N + 1) {
            break;
        }

        queries.push_back(progress);
        int pointer = arr[progress];
        arr[progress] = 0;

        while (pointer != 0) {
            queries.push_back(pointer);
            int temp = pointer;
            pointer = arr[pointer];
            arr[temp] = temp;
        }
    }

    cout << queries.size() << '\n';

    for (size_t i = 0; i < queries.size(); i++) {
        cout << queries[i] << ' ' << 1 << ' ' << N << '\n';
    }
}
