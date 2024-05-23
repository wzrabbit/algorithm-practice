#include <iostream>
using namespace std;

int tree[1200001];
int indexes[300001];
int answer[300001];

int get_sum(int start, int end, int index, int left, int right) {
    if (end < left || right < start) {
        return 0;
    }

    if (left <= start && end <= right) {
        return tree[index];
    }

    int mid = (start + end) / 2;
    return get_sum(start, mid, index * 2, left, right) +
           get_sum(mid + 1, end, index * 2 + 1, left, right);
}

void update(int start, int end, int index, int target) {
    if (target < start || target > end) {
        return;
    }

    tree[index] += 1;

    if (start == end) {
        return;
    }

    int mid = (start + end) / 2;
    update(start, mid, index * 2, target);
    update(mid + 1, end, index * 2 + 1, target);
}

int get_nth_index(int start, int end, int index, int target) {
    if (start == end) {
        return start;
    }

    int mid = (start + end) / 2;
    int left_space = mid - start + 1 - tree[index * 2];

    if (left_space >= target) {
        return get_nth_index(start, mid, index * 2, target);
    } else {
        return get_nth_index(mid + 1, end, index * 2 + 1, target - left_space);
    }
}

// 우와 세그트리다 살려줘요
int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N;
    cin >> N;

    answer[1] = 1;
    indexes[1] = 1;
    update(1, N, 1, 1);

    for (int i = 1; i <= N - 1; i++) {
        int p, x;
        cin >> p >> x;

        int p_index = indexes[p];
        int left_space = p_index - get_sum(1, N, 1, 1, p_index);
        x += left_space;
        x = (x - 1) % (N - i) + 1;

        int found_index = get_nth_index(1, N, 1, x);
        indexes[i + 1] = found_index;
        answer[found_index] = i + 1;
        update(1, N, 1, found_index);
    }

    for (int i = 1; i <= N; i++) {
        cout << answer[i] << '\n';
    }
}
