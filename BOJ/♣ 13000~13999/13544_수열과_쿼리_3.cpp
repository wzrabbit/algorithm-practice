#include <iostream>
using namespace std;

int arr[100001];
int tree[24][100001];

void make_merge_sort_tree(int start, int end, int level) {
    if (start == end) {
        tree[level][start] = arr[start];
        return;
    }

    int mid = (start + end) / 2;
    make_merge_sort_tree(start, mid, level + 1);
    make_merge_sort_tree(mid + 1, end, level + 1);

    int left = start;
    int right = mid + 1;
    int index = start;

    while (left <= mid && right <= end) {
        if (tree[level + 1][left] < tree[level + 1][right]) {
            tree[level][index++] = tree[level + 1][left++];
        } else {
            tree[level][index++] = tree[level + 1][right++];
        }
    }

    for (int i = left; i <= mid; i++) {
        tree[level][index++] = tree[level + 1][i];
    }

    for (int i = right; i <= end; i++) {
        tree[level][index++] = tree[level + 1][i];
    }
}

int do_binary_search(int left, int right, int level, int value) {
    int start = left;
    int end = right;
    int mid;

    while (start <= end) {
        mid = (start + end) / 2;

        if (tree[level][mid] > value) {
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }

    return right - left + 1 - (end - left + 1);
}

int get_greater_value_count(int start, int end, int level, int left, int right, int value) {
    if (start > right || end < left) {
        return 0;
    }

    if (start < left || right < end) {
        int mid = (start + end) / 2;
        return get_greater_value_count(start, mid, level + 1, left, right, value) +
               get_greater_value_count(mid + 1, end, level + 1, left, right, value);
    }

    return do_binary_search(start, end, level, value);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }

    make_merge_sort_tree(1, N, 1);

    int Q;
    cin >> Q;

    int left, right, value, last_ans = 0;

    while (Q--) {
        int a, b, c;
        cin >> a >> b >> c;

        left = a ^ last_ans;
        right = b ^ last_ans;
        value = c ^ last_ans;

        last_ans = get_greater_value_count(1, N, 1, left, right, value);
        cout << last_ans << '\n';
    }
}
