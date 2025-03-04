#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    string KSA = "KSA";
    vector<int> ksa_count(3);
    int best_length = 0;
    int index = 0;

    string X;
    cin >> X;

    for (char cur : X) {
        if (cur == 'K') {
            ksa_count[0] += 1;
        } else if (cur == 'S') {
            ksa_count[1] += 1;
        } else {
            ksa_count[2] += 1;
        }
    }

    while (ksa_count[index] > 0) {
        best_length += 1;
        ksa_count[index] -= 1;
        index = (index + 1) % 3;
    }

    int answer = X.size();
    index = (best_length + 2) % 3;

    for (int i = (int)X.size(); i >= 0; i--) {
        if (best_length == 0) {
            break;
        }

        if (X[i] == KSA[index]) {
            answer -= 1;
            index = (index + 2) % 3;
            best_length -= 1;
        }
    }

    cout << answer;
}
