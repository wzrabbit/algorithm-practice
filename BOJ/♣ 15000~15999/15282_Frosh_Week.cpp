#include <algorithm>
#include <iostream>
using namespace std;

int work[200000];
int song[200000];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N, M;
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        cin >> work[i];
    }

    for (int i = 0; i < M; i++) {
        cin >> song[i];
    }

    sort(work, work + N);
    sort(song, song + M);

    int l = 0;
    int r = 0;
    int success = 0;

    while (l < N && r < M) {
        if (work[l] <= song[r]) {
            l++;
            r++;
            success++;
        } else {
            r++;
        }
    }

    cout << success;
}