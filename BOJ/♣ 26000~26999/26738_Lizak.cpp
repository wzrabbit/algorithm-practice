#include <algorithm>
#include <iostream>
#include <map>
#define INF 600000
using namespace std;

int arr[500000];
map<int, int> taste_cnt;
int qualified_cnt = 0;
int shortest_length = INF;

void add_taste(int taste) {
    if (taste_cnt.find(taste) == taste_cnt.end()) {
        taste_cnt[taste] = 1;
        return;
    }

    taste_cnt[taste] += 1;
    if (taste_cnt[taste] == 3) {
        qualified_cnt += 1;
    }
}

void delete_taste(int taste) {
    taste_cnt[taste] -= 1;
    if (taste_cnt[taste] == 2) {
        qualified_cnt -= 1;
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    int l = 0;
    int r = 0;

    while (true) {
        if (qualified_cnt >= 1) {
            shortest_length = min(shortest_length, r - l);
            delete_taste(arr[l]);
            l++;
        } else {
            if (r == N) break;
            add_taste(arr[r]);
            r++;
        }
    }

    if (shortest_length == INF) {
        cout << "NIE";
    } else {
        cout << shortest_length;
    }
}