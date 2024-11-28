#include <iostream>
using namespace std;

bool S[720000];
bool T[360000];
int pi[360000];
int N;

void make_pi_array() {
    int l = 0;

    for (int r = 1; r < 360000; r++) {
        while (l > 0 && T[l] != T[r]) {
            l = pi[l - 1];
        }

        if (T[l] == T[r]) {
            pi[r] = l + 1;
            l += 1;
        }
    }
}

bool perform_kmp() {
    int index = 0;

    for (int i = 0; i < 720000; i++) {
        while (index > 0 && S[i] != T[index]) {
            index = pi[index - 1];
        }

        if (S[i] == T[index]) {
            index += 1;

            if (index == 360000) {
                return true;
            }
        }
    }

    return false;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N;

    for (int i = 0; i < N; i++) {
        int cur;
        cin >> cur;

        S[cur] = 1;
        S[cur + 360000] = 1;
    }

    for (int i = 0; i < N; i++) {
        int cur;
        cin >> cur;

        T[cur] = 1;
    }

    make_pi_array();

    if (perform_kmp()) {
        cout << "possible";
    } else {
        cout << "impossible";
    }
}
