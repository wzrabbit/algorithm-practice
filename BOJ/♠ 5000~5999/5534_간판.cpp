#include <iostream>
#include <string>
using namespace std;

bool is_recyclable(string &goal, string &candidate) {
    for (int i = 0; i < (int)candidate.size(); i++) {
        for (int j = 1; j <= (int)candidate.size() - 1; j++) {
            string cur = "";

            for (int k = i; k <= (int)candidate.size() - 1; k += j) {
                cur += candidate[k];

                if (cur.size() == goal.size()) {
                    if (cur == goal) {
                        return true;
                    }
                    break;
                }
            }
        }
    }

    return false;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N;
    string S;
    cin >> N >> S;

    int answer = 0;

    for (int i = 1; i <= N; i++) {
        string candidate;
        cin >> candidate;

        if (is_recyclable(S, candidate)) {
            answer += 1;
        }
    }

    cout << answer;
}
