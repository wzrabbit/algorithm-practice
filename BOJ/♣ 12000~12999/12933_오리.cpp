#include <iostream>
#include <string>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int max_duck_count = 0;
    int cur_duck_count = 0;
    int q_count = 0;
    int u_count = 0;
    int a_count = 0;
    int c_count = 0;

    string S;
    cin >> S;

    bool is_valid = true;

    for (size_t i = 0; i < S.length(); i++) {
        switch (S[i]) {
            case 'q':
                q_count += 1;
                cur_duck_count += 1;
                max_duck_count = max(max_duck_count, cur_duck_count);
                break;
            case 'u':
                if (q_count == 0) {
                    is_valid = false;
                }
                q_count -= 1;
                u_count += 1;
                break;
            case 'a':
                if (u_count == 0) {
                    is_valid = false;
                }
                u_count -= 1;
                a_count += 1;
                break;
            case 'c':
                if (a_count == 0) {
                    is_valid = false;
                }
                a_count -= 1;
                c_count += 1;
                break;
            case 'k':
                if (c_count == 0) {
                    is_valid = false;
                }
                c_count -= 1;
                cur_duck_count -= 1;
                break;
        }

        if (!is_valid) {
            break;
        }
    }

    if (q_count + u_count + a_count + c_count != 0) {
        is_valid = false;
    }

    if (!is_valid) {
        cout << -1;
    } else {
        cout << max_duck_count;
    }
}
