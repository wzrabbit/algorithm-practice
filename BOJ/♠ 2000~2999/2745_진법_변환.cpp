#include <iostream>
#include <string>
using namespace std;

int main() {
    string S;
    int B;

    cin >> S >> B;

    int answer = 0;
    int multiplier = 1;

    for (int i = S.size() - 1; i >= 0; i--) {
        if (S[i] >= 'A' && S[i] <= 'Z') {
            answer += (S[i] - 'A' + 10) * multiplier;
        } else {
            answer += (S[i] - '0') * multiplier;
        }

        multiplier *= B;
    }

    cout << answer;
}