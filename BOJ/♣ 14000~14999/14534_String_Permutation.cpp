#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int T;
    cin >> T;

    for (int t = 1; t <= T; t++) {
        string word;
        cin >> word;

        vector<int> order(word.length());

        for (size_t i = 0; i < word.length(); i++) {
            order[i] = i;
        }

        cout << "Case # " << t << ":\n";

        do {
            for (size_t i = 0; i < order.size(); i++) {
                cout << word[order[i]];
            }

            cout << '\n';
        } while (next_permutation(order.begin(), order.end()));
    }
}
