#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int T;
    cin >> T;

    while (T--) {
        int N;
        string S;
        vector<int> state = {0};

        cin >> N >> S;

        for (int i = 0; i < N; i++) {
            if (S[i] == 'A') {
                state.push_back(0);
            } else {
                state.back() += 1;
            }
        }

        int index = int(state.size()) - 2;

        while (index >= 0) {
            if (state[index + 1] <= 1) {
                index -= 1;
                continue;
            }

            state[index] += 1;
            state[index + 1] -= 2;
        }

        for (size_t i = 0; i < state.size(); i++) {
            for (int j = 0; j < state[i]; j++) {
                cout << 'B';
            }

            if (i != int(state.size()) - 1) {
                cout << 'A';
            }
        }

        cout << '\n';
    }
}
