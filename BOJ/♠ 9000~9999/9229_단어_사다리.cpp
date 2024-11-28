#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool is_ladder(string &A, string &B) {
    if (A.size() != B.size()) {
        return false;
    }

    int diff_count = 0;

    for (size_t i = 0; i < A.size(); i++) {
        if (A[i] != B[i]) {
            diff_count += 1;
        }
    }

    return diff_count == 1;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    while (true) {
        vector<string> words;
        bool correct = true;

        while (true) {
            string word;
            cin >> word;

            if (words.empty() && word == "#") {
                return 0;
            }

            if (word == "#") {
                break;
            }

            words.push_back(word);
        }

        for (int i = 0; i < int(words.size()) - 1; i++) {
            if (!is_ladder(words[i], words[i + 1])) {
                correct = false;
                break;
            }
        }

        if (correct) {
            cout << "Correct\n";
        } else {
            cout << "Incorrect\n";
        }
    }
}
