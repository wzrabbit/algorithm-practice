#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
typedef long long ll;
using namespace std;

ll lengths[50];
vector<string> results;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        results.clear();

        for (int i = 0; i < N; i++) {
            cin >> lengths[i];
        }

        sort(lengths, lengths + N);

        for (int i = 0; i < N - 2; i++) {
            for (int j = i + 1; j < N - 1; j++) {
                for (int k = j + 1; k < N; k++) {
                    if (lengths[i] * lengths[i] + lengths[j] * lengths[j] == lengths[k] * lengths[k]) {
                        string data_string = to_string(lengths[i]) + " " + to_string(lengths[j]) + " " + to_string(lengths[k]);
                        results.push_back(data_string);
                    }
                }
            }
        }

        sort(results.begin(), results.end());

        if (results.size() > 0) {
            cout << "Found Pythogorean triples:  ";

            for (size_t i = 0; i < results.size(); i++) {
                cout << "{" << results[i] << "} ";
            }

            cout << '\n';
        } else {
            cout << "No Pythogorean triples found in the sequence.\n";
        }
    }
}