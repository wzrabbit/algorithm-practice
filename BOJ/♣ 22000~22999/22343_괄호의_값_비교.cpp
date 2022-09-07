#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int A_score[1500001];
int B_score[1500001];
string A_str, B_str;

void reset(int len) {
    for (int i = 0; i < len; i++) {
        A_score[i] = 0;
        B_score[i] = 0;
    }
}

void calc_score(string& str, int score[], int len) {
    int level = 0;

    for (size_t i = 0; i < str.size(); i++) {
        if (str[i] == '(')
            level++;
        else
            level--;

        if (i > 0 && str[i - 1] == '(' && str[i] == ')')
            score[level]++;
    }

    for (int i = 1; i < len; i++) {
        score[i] += score[i - 1] / 2;
        score[i - 1] %= 2;
    }
}

char compare(int len) {
    for (int i = len - 1; i >= 0; i--) {
        if (A_score[i] > B_score[i])
            return '>';
        else if (A_score[i] < B_score[i])
            return '<';
    }
    return '=';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int T;
    cin >> T;

    while (T--) {
        cin >> A_str >> B_str;
        int score_len = max(A_str.size(), B_str.size()) / 2;
        reset(score_len);
        calc_score(A_str, A_score, score_len);
        calc_score(B_str, B_score, score_len);
        cout << compare(score_len) << '\n';
    }
}