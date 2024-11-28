#include <iostream>
#include <string>
using namespace std;

/**
 * 1. fail(N)의 prefix는 전체 문자열에서 정의 상 4회 이상 등장하므로, 항상 조건을 만족한다.
 * 2. N의 경우에는 확정이 아니므로 직접 kmp를 돌려서 찾아본다.
 */

string S;
int fail[1000000];
int N;

void make_fail_array() {
    int l = 0;

    for (int r = 1; r < int(S.size()); r++) {
        while (l > 0 && S[l] != S[r]) {
            l = fail[l - 1];
        }

        if (S[l] == S[r]) {
            fail[r] = l + 1;
            l += 1;
        }
    }
}

bool perform_kmp(int word_length) {
    int index = 0;

    for (int i = 1; i < N - 1; i++) {
        while (index > 0 && S[i] != S[index]) {
            index = fail[index - 1];
        }

        if (S[i] == S[index]) {
            if (index == word_length - 1) {
                return true;
            }

            index += 1;
        }
    }

    return false;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> S;
    N = int(S.size());

    make_fail_array();

    if (fail[N - 1] == 0) {
        cout << -1;
        return 0;
    }

    int T = 0;

    if (perform_kmp(fail[N - 1])) {
        T = fail[N - 1];
    } else {
        T = fail[fail[N - 1] - 1];
    }

    if (T == 0) {
        cout << -1;
    } else {
        for (int i = 0; i < T; i++) {
            cout << S[i];
        }
    }
}
