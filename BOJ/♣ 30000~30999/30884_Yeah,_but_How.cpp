#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    string S;
    cin >> S;

    cout << '(';

    for (size_t i = 0; i < S.size() - 1; i++) {
        if (S[i] == '(' && S[i + 1] == ')') {
            cout << "1";
        } else if (S[i] == ')' && S[i + 1] == '(') {
            cout << "+";
        }

        cout << S[i + 1];
    }
}
