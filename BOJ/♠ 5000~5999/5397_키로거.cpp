#include <iostream>
#include <algorithm>
#include <string>
#include <deque>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int tc;
    cin >> tc;

    while (tc--) {
        string log;
        deque<char> alpha;
        deque<char> beta;
        cin >> log;

        for (size_t i = 0; i < log.length(); i++) {
            if (log[i] == '<') {
                if (!alpha.empty()) {
                    beta.push_front(alpha.back());
                    alpha.pop_back();
                }
            }
            else if (log[i] == '>') {
                if (!beta.empty()) {
                    alpha.push_back(beta.front());
                    beta.pop_front();
                }
            }
            else if (log[i] == '-') {
                if (!alpha.empty()) {
                    alpha.pop_back();
                }
            }
            else {
                alpha.push_back(log[i]);
            }
        }

        for (size_t i = 0; i < alpha.size(); i++) {
            cout << alpha[i];
        }
        for (size_t i = 0; i < beta.size(); i++) {
            cout << beta[i];
        }
        cout << '\n';
    }
}