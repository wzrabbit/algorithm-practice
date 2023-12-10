#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int L, N;
    string S;
    cin >> L >> N >> S;

    int hw_size = 0;
    vector<int> h_indexes;

    for (int i = 0; i < L; i++) {
        if (S[i] == 'h') {
            h_indexes.push_back(hw_size);
            hw_size += 1;
        }

        if (S[i] == 'w') {
            hw_size += 1;
        }

        if ((S[i] == 'w' || S[i] == 'h') && i != L - 1) {
            continue;
        }

        int prev_index = -1;

        for (size_t i = 0; i < h_indexes.size(); i++) {
            h_indexes[i] = max(h_indexes[i] - N, prev_index + 1);
            prev_index = h_indexes[i];
        }

        int index = 0;

        for (int j = 0; j < hw_size; j++) {
            if (index < h_indexes.size() && j == h_indexes[index]) {
                cout << 'h';
                index += 1;
            } else {
                cout << 'w';
            }
        }

        hw_size = 0;
        h_indexes.clear();

        if (S[i] != 'w' && S[i] != 'h') {
            cout << S[i];
        }
    }
}