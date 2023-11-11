#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

struct Photo {
    int n, p, d;
};

bool operator<(const Photo& a, const Photo& b) {
    return a.n < b.n;
}

Photo photos[21];
int N, Q;

void give_point(int no, int date) {
    for (int i = 1; i <= N; i++) {
        if (photos[i].n == no) {
            photos[i].p += 1;
            return;
        }
    }

    for (int i = 1; i <= N; i++) {
        if (photos[i].n == 0) {
            photos[i] = {no, 1, date};
            return;
        }
    }

    int worst_index = 1;
    Photo worst_photo = photos[1];

    for (int i = 2; i <= N; i++) {
        Photo cur = photos[i];

        if (cur.p > worst_photo.p) {
            continue;
        }

        if (cur.p < worst_photo.p) {
            worst_index = i;
            worst_photo = cur;
            continue;
        }

        if (cur.d > worst_photo.d) {
            continue;
        }

        worst_index = i;
        worst_photo = cur;
    }

    photos[worst_index] = {no, 1, date};
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N >> Q;

    for (int i = 1; i <= Q; i++) {
        int cur;
        cin >> cur;

        give_point(cur, i);
    }

    sort(photos + 1, photos + N + 1);

    for (int i = 1; i <= N; i++) {
        if (photos[i].n != 0) {
            cout << photos[i].n << ' ';
        }
    }
}