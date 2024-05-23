#include <iostream>
#include <vector>
typedef long long ll;
using namespace std;

int before_arr[100001];
int after_arr[100001];
int before_tree[24][100001];
int after_tree[24][100001];

void make_merge_sort_tree(int start, int end, int level, int tree[][100001], int arr[]) {
    if (start == end) {
        tree[level][start] = arr[start];
        return;
    }

    int mid = (start + end) / 2;
    make_merge_sort_tree(start, mid, level + 1, tree, arr);
    make_merge_sort_tree(mid + 1, end, level + 1, tree, arr);

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

int do_binary_search(int left, int right, int level, int value, int tree[][100001]) {
    int start = left;
    int end = right;
    int mid;

    while (start <= end) {
        mid = (start + end) / 2;

        if (tree[level][mid] < value) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }

    return start - left;
}

int get_smaller_value_count(int start, int end, int level, int left, int right, int value, int tree[][100001]) {
    if (start > right || end < left) {
        return 0;
    }

    if (start < left || right < end) {
        int mid = (start + end) / 2;
        return get_smaller_value_count(start, mid, level + 1, left, right, value, tree) +
               get_smaller_value_count(mid + 1, end, level + 1, left, right, value, tree);
    }

    return do_binary_search(start, end, level, value, tree);
}

ll get_parity(int N, int tree[][100001], int arr[]) {
    ll parity = 0;

    for (int i = 1; i <= N; i++) {
        parity += (ll)get_smaller_value_count(1, N, 1, i + 1, N, arr[i], tree);
    }

    return parity;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> before_arr[i];
    }

    for (int i = 1; i <= N; i++) {
        cin >> after_arr[i];
    }

    make_merge_sort_tree(1, N, 1, before_tree, before_arr);
    make_merge_sort_tree(1, N, 1, after_tree, after_arr);

    ll before_parity = get_parity(N, before_tree, before_arr);
    ll after_parity = get_parity(N, after_tree, after_arr);

    if (before_parity % 2 == after_parity % 2) {
        cout << "Possible";
    } else {
        cout << "Impossible";
    }
}
