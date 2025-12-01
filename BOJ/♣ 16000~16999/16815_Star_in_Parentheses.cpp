#include <iostream>
#include <string>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    string S;
    cin >> S;

    int answer = 0;

    for (size_t i = 0; i < S.size(); i++) {
        for (size_t j = i; j < S.size(); j++) {
            int state = 0;
            bool success = true;
            bool has_star = false;

            if (S[i] != '(' || S[j] != ')') continue;

            for (int k = i + 1; k <= j - 1; k++) {
                if (S[k] == '(') state += 1;
                if (S[k] == ')') state -= 1;
                if (S[k] == '*') has_star = true;

                if (state < 0) {
                    success = false;
                    break;
                }
            }

            if (success && state == 0 && has_star) {
                answer += 1;
            }
        }
    }

    cout << answer;
}
