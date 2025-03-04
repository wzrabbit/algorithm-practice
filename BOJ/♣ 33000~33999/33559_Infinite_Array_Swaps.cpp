#include <algorithm>
#include <iostream>
using namespace std;

int A[100001];
int B[100001];
int answer_A[100001];
int answer_B[100001];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }

    for (int i = 1; i <= N; i++) {
        cin >> B[i];
    }

    sort(A + 1, A + N + 1);
    sort(B + 1, B + N + 1);

    int l = 1;
    int r = 1;
    int i = 1;

    while (l <= N && r <= N) {
        if (A[l] > B[r]) {
            r += 1;
            continue;
        }

        if (A[l] < B[r]) {
            l += 1;
            continue;
        }

        answer_A[i] = answer_B[i] = A[l];
        A[l] = 0;
        B[r] = 0;
        l += 1;
        r += 1;
        i += 1;
    }

    int temp_i = i;

    for (int i = 1; i <= N; i++) {
        if (A[i] != 0) {
            answer_A[temp_i] = A[i];
            temp_i += 1;
        }
    }

    temp_i = i;

    for (int i = 1; i <= N; i++) {
        if (B[i] != 0) {
            answer_B[temp_i] = B[i];
            temp_i += 1;
        }
    }

    cout << i - 1 << '\n';

    for (int i = 1; i <= N; i++) {
        cout << answer_A[i] << ' ';
    }
    cout << '\n';

    for (int i = 1; i <= N; i++) {
        cout << answer_B[i] << ' ';
    }
}
