#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N;
    cin >> N;

    while (N--) {
        string S, E;
        cin >> S >> E;
        vector<int> index[26];
        bool success = true;
        int sp = S.size() - 1;
        int ep = E.size() - 1;
        int prev = S.size();

        for (int i = 0; i < S.size(); i++) {
            index[S[i] - 'A'].push_back(i);
        }

        while (sp >= 0 && ep >= 0) {
            if (S[sp] == E[ep]) {
                if (index[S[sp] - 'A'].back() < prev) {
                    index[S[sp] - 'A'].pop_back();
                    prev = sp;
                    sp--;
                    ep--;
                } else {
                    success = false;
                    break;
                }
            } else {
                sp--;
            }
        }

        if (!success || (sp < 0 && ep >= 0)) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
        }
    }
}