#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Clone {
    int i;
    char c;
};

bool operator<(const Clone &a, const Clone &b) {
    return a.c < b.c;
}

int element_count[27];
int arr[200001];
Clone clones[200001];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N;
    string S;
    cin >> N >> S;

    for (int i = 1; i <= N; i++) {
        clones[i] = {i, S[i - 1]};
        element_count[S[i - 1] - 'a' + 1] += 1;
    }

    for (int i = 1; i <= 26; i++) {
        if (element_count[i] > N / 2) {
            cout << -1;
            return 0;
        }
    }

    sort(clones + 1, clones + N + 1);

    cout << N - N / 2 << '\n';

    for (int i = 1; i <= N - N / 2; i++) {
        int a = clones[i].i;
        int b = clones[i + N / 2].i;

        if (a > b) {
            swap(a, b);
        }

        cout << a << ' ' << b << '\n';
    }
}
