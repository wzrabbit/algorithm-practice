#include <algorithm>
#include <iostream>
#define MAX 1000000
#define SQRT 1000
using namespace std;

int parent[1000001];
int scale[1000001];
int min_factor[1000001];

int get_parent(int child) {
    if (parent[child] == 0) return child;
    return parent[child] = get_parent(parent[child]);
}

void merge(int a, int b) {
    a = get_parent(a);
    b = get_parent(b);

    if (a == b) return;

    parent[b] = a;
    scale[a] += scale[b];
}

void create_min_factors() {
    for (int i = 2; i <= MAX; i++) {
        min_factor[i] = i;
    }

    for (int i = 2; i <= SQRT; i++) {
        if (min_factor[i] != i) continue;

        for (int j = i; j <= MAX; j += i) {
            min_factor[j] = min(min_factor[j], i);
        }
    }
}

void merge_all_factors(int origin, int cur) {
    if (cur == 1) return;
    merge(origin, min_factor[cur]);
    merge_all_factors(origin, cur / min_factor[cur]);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        int cur;
        cin >> cur;
        scale[cur] += 1;
    }

    create_min_factors();

    for (int i = 2; i <= MAX; i++) {
        if (scale[i] == 0) continue;
        merge_all_factors(i, i);
    }

    int max_scale = 0;
    for (int i = 2; i <= MAX; i++) {
        max_scale = max(max_scale, scale[i]);
    }

    cout << max_scale;
}