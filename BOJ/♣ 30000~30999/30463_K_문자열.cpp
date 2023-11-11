#include <iostream>
#include <string>
typedef long long ll;
using namespace std;

ll bit_counts[1024];
bool is_k_bit[1024];

int get_one_bit_count(int num) {
    int one_bit_count = 0;

    while (num > 0) {
        if ((num & 1) == 1) {
            one_bit_count += 1;
        }

        num >>= 1;
    }

    return one_bit_count;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N, K;
    cin >> N >> K;

    for (int i = 1; i <= N; i++) {
        string S;
        cin >> S;

        int cur_bit = 0;

        for (int i = 0; i < 10; i++) {
            cur_bit |= (1 << (S[i] - '0'));
        }

        bit_counts[cur_bit] += 1;
    }

    for (int i = 0; i <= 1023; i++) {
        is_k_bit[i] = get_one_bit_count(i) == K;
    }

    ll answer_count = 0;

    for (int i = 1; i <= 1023; i++) {
        for (int j = i; j <= 1023; j++) {
            if (i == j) {
                if (is_k_bit[i]) {
                    answer_count += bit_counts[i] * (bit_counts[i] - 1) / 2;
                }

                continue;
            }

            if (is_k_bit[i | j]) {
                answer_count += bit_counts[i] * bit_counts[j];
            }
        }
    }

    cout << answer_count;
}
