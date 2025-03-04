#include <algorithm>
#include <iostream>
#define INF 1'000'000
using namespace std;

char before[502][502];
char after[502][502];
char temp[502][502];
int N;

void rotate_clockwise() {
    for (int r = 1; r <= N; r++) {
        for (int c = 1; c <= N; c++) {
            temp[c][N - r + 1] = before[r][c];
        }
    }

    for (int r = 1; r <= N; r++) {
        for (int c = 1; c <= N; c++) {
            before[r][c] = temp[r][c];
        }
    }
}

int get_mismatch_count() {
    int mismatch_count = 0;

    for (int r = 1; r <= N; r++) {
        for (int c = 1; c <= N; c++) {
            if (before[r][c] != after[r][c]) {
                mismatch_count += 1;
            }
        }
    }

    return mismatch_count;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N;

    for (int r = 1; r <= N; r++) {
        cin >> (before[r] + 1);
    }

    for (int r = 1; r <= N; r++) {
        cin >> (after[r] + 1);
    }

    int answer = INF;

    for (int i = 0; i < 4; i++) {
        answer = min(answer, min(4 - i, i) + get_mismatch_count());
        rotate_clockwise();
    }

    cout << answer;
}
