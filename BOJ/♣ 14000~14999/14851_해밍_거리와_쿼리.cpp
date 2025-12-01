#include <algorithm>
#include <bitset>
#include <iostream>
#include <string>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    string S, T;
    cin >> S >> T;

    bitset<200000> A, B, result;

    for (size_t i = 0; i < S.size(); i++) {
        if (S[i] == '1') A.set(i);
    }

    for (size_t i = 0; i < T.size(); i++) {
        if (T[i] == '1') B.set(i);
    }

    int Q;
    cin >> Q;

    while (Q--) {
        int a, b, c;
        cin >> a >> b >> c;

        result = ((A >> a) ^ (B >> b)) << (200000 - c);

        cout << result.count() << '\n';
    }
}
