#include <iostream>
#include <set>
#include <string>
#define MOD 1'000'000'007
typedef long long ll;
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int T;
    cin >> T;

    for (int t = 1; t <= T; t++) {
        string S;
        cin >> S;

        ll answer = 1;

        for (int i = 0; i < S.size(); i++) {
            set<int> possible_letters;

            for (int j = i - 1; j <= i + 1; j++) {
                if (j >= 0 && j < S.size()) {
                    possible_letters.insert(S[j]);
                }
            }

            answer = answer * possible_letters.size() % MOD;
        }

        cout << "Case #" << t << ": " << answer << '\n';
    }
}