#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
typedef long long ll;
using namespace std;

vector<vector<int>> orders;
vector<int> arr;
vector<ll> seg_tree;

void compress(vector<int> &arr) {
    vector<int> sorted_arr(arr);
    sort(sorted_arr.begin(), sorted_arr.end());
    map<int, int> compressed;

    int id = 1;
    compressed[sorted_arr[0]] = 0;

    for (size_t i = 1; i < sorted_arr.size(); i++) {
        if (sorted_arr[i] != sorted_arr[i - 1]) {
            compressed[sorted_arr[i]] = id;
            id += 1;
        }
    }

    for (size_t i = 0; i < arr.size(); i++) {
        arr[i] = compressed[arr[i]];
    }
}

void update_value(int start, int end, int index, int target, ll value) {
    if (target < start || target > end) return;
    seg_tree[index] += value;
    if (start == end) return;

    int mid = (start + end) / 2;
    update_value(start, mid, index * 2 + 1, target, value);
    update_value(mid + 1, end, index * 2 + 2, target, value);
}

ll get_sum(int start, int end, int index, int left, int right) {
    if (right < start || end < left) return 0;
    if (left <= start && end <= right) return seg_tree[index];

    int mid = (start + end) / 2;
    return get_sum(start, mid, index * 2 + 1, left, right) +
           get_sum(mid + 1, end, index * 2 + 2, left, right);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N;
    cin >> N;

    arr.resize(N);
    orders.resize(N);
    seg_tree.resize(N * 4);

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    compress(arr);

    for (int i = 0; i < N; i++) {
        orders[i].push_back(arr[i]);
    }

    ll answer = 0;

    for (int i = 0; i < N; i++) {
        for (int cur : orders[i]) {
            answer += get_sum(0, N - 1, 0, cur + 1, N - 1);
        }

        for (int cur : orders[i]) {
            update_value(0, N - 1, 0, cur, 1);
        }
    }

    cout << answer;
}
