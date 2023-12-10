#include <algorithm>
#include <iostream>
#include <string>
#define LIMIT 1'000'000'000'000'000'000
#define INF LIMIT + 1
typedef long long ll;
using namespace std;

string NATO[26] = {
    "ALFA",
    "BRAVO",
    "CHARLIE",
    "DELTA",
    "ECHO",
    "FOXTROT",
    "GOLF",
    "HOTEL",
    "INDIA",
    "JULIETT",
    "KILO",
    "LIMA",
    "MIKE",
    "NOVEMBER",
    "OSCAR",
    "PAPA",
    "QUEBEC",
    "ROMEO",
    "SIERRA",
    "TANGO",
    "UNIFORM",
    "VICTOR",
    "WHISKEY",
    "XRAY",
    "YANKEE",
    "ZULU"};

ll prefix[31][200001];
ll dp[31][26];
string S;
ll performed_count = 0;

void init_dp() {
    fill(&dp[0][0], &dp[0][26], 1);

    for (int i = 1; i <= 30; i++) {
        for (int j = 0; j < 26; j++) {
            for (size_t k = 0; k < NATO[j].size(); k++) {
                dp[i][j] += dp[i - 1][NATO[j][k] - 'A'];

                if (dp[i][j] > LIMIT) {
                    dp[i][j] = INF;
                    break;
                }
            }
        }
    }
}

void make_prefix() {
    for (int i = 0; i <= 30; i++) {
        for (size_t j = 1; j <= S.size(); j++) {
            prefix[i][j] = prefix[i][j - 1] + dp[i][S[j - 1] - 'A'];

            if (prefix[i][j] > LIMIT) {
                prefix[i][j] = INF;
            }
        }
    }
}

char find_letter(char letter, ll level, ll start_index, ll target_index) {
    if (level == -1) {
        return letter;
    }

    ll cur_index = start_index;
    ll selected_index;

    for (size_t i = 0; i < NATO[letter - 'A'].size(); i++) {
        if (cur_index + dp[level][NATO[letter - 'A'][i] - 'A'] > target_index) {
            selected_index = i;
            break;
        }

        cur_index += dp[level][NATO[letter - 'A'][i] - 'A'];
    }

    return find_letter(NATO[letter - 'A'][selected_index], level - 1, cur_index, target_index);
}

char find_first_letter(ll target_index) {
    int start = 1;
    int end = S.size();
    int mid;

    while (start <= end) {
        mid = (start + end) / 2;

        if (prefix[performed_count][mid] >= target_index) {
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }

    return find_letter(S[start - 1], performed_count - 1, prefix[performed_count][start - 1] + 1, target_index);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    init_dp();

    int Q;
    cin >> S >> Q;

    make_prefix();

    while (Q--) {
        int query_no;
        ll value;
        cin >> query_no >> value;

        if (query_no == 1) {
            performed_count = min(performed_count + value, 30LL);
            continue;
        }

        cout << find_first_letter(value);
    }
}
