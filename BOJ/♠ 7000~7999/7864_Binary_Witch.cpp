#include <iostream>
#include <map>
#include <string>
using namespace std;

int N, L;
string S;
map<string, char> predictions;

void predict() {
    bool chosen = false;

    for (int j = 13; j >= 1; j--) {
        if ((int)S.size() < j) {
            continue;
        }

        string cur = S.substr(S.size() - j, j);
        if (predictions.find(cur) != predictions.end()) {
            char predicted = predictions[cur];
            cout << predicted;
            S += predicted;
            chosen = true;
            break;
        }
    }

    if (!chosen) {
        cout << '0';
        S += '0';
    }

    for (int i = 1; i <= 13; i++) {
        if ((int)S.size() < i + 1) {
            break;
        }

        predictions[S.substr(S.size() - i - 1, i)] = S[S.size() - 1];
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N >> L >> S;

    for (int i = 1; i <= 13; i++) {
        for (int j = 0; j < N - i; j++) {
            predictions[S.substr(j, i)] = S[j + i];
        }
    }

    for (int i = 1; i <= L; i++) {
        predict();
    }
}