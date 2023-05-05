#include <iostream>
#include <string>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    string S;
    cin >> S;

    int dp_count = 0;
    int cu_count = 0;

    for (size_t i = 0; i < S.size(); i++) {
        if (S[i] == 'D' || S[i] == 'P') {
            dp_count += 1;
        } else {
            cu_count += 1;
        }
    }

    if (cu_count > (dp_count + 1) / 2) {
        cout << "U";
    }

    if (dp_count >= 1) {
        cout << "DP";
    }
}