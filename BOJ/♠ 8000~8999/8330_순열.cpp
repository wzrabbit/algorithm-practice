#include <iostream>
#define INF 999999
using namespace std;

int arr[200001];
int seg[800001];
int lazy[800001];
int N;

int init_seg(int start, int end, int index) {
    if (start == end) {
        return seg[index] = start - 1;
    }

    int mid = (start + end) / 2;

    return seg[index] = min(
               init_seg(start, mid, index * 2),
               init_seg(mid + 1, end, index * 2 + 1));
}

void propagate(int start, int end, int index) {
    if (lazy[index] == 0) {
        return;
    }

    seg[index] += lazy[index];

    if (start != end) {
        lazy[index * 2] += lazy[index];
        lazy[index * 2 + 1] += lazy[index];
    }

    lazy[index] = 0;
}

void update(int start, int end, int index, int left, int right, int value) {
    propagate(start, end, index);

    if (end < left || start > right) {
        return;
    }

    if (start >= left && end <= right) {
        seg[index] += value;

        if (start != end) {
            lazy[index * 2] += value;
            lazy[index * 2 + 1] += value;
        }

        return;
    }

    int mid = (start + end) / 2;
    update(start, mid, index * 2, left, right, value);
    update(mid + 1, end, index * 2 + 1, left, right, value);
    seg[index] = min(seg[index * 2], seg[index * 2 + 1]);
}

int get_minimum_value(int start, int end, int index, int left, int right) {
    propagate(start, end, index);

    if (end < left || start > right) {
        return INF;
    }

    if (start >= left && end <= right) {
        return seg[index];
    }

    int mid = (start + end) / 2;

    return min(
        get_minimum_value(start, mid, index * 2, left, right),
        get_minimum_value(mid + 1, end, index * 2 + 1, left, right));
}

bool is_ok() {
    int minimum_value = get_minimum_value(1, N, 1, 1, N);
    return minimum_value >= N;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }

    init_seg(1, N, 1);

    for (int i = 1; i <= N; i++) {
        update(1, N, 1, 1, arr[i], 1);
    }

    if (is_ok()) {
        cout << "TAK\n";
    } else {
        cout << "NIE\n";
    }

    int Q;
    cin >> Q;

    for (int i = 1; i <= Q; i++) {
        int index, value;
        cin >> index >> value;

        update(1, N, 1, 1, arr[index], -1);
        arr[index] = value;
        update(1, N, 1, 1, value, 1);

        if (is_ok()) {
            cout << "TAK\n";
        } else {
            cout << "NIE\n";
        }
    }
}
