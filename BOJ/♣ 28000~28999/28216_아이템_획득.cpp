#include <algorithm>
#include <iostream>
#include <vector>
#define MAX 200000
typedef long long ll;
using namespace std;

struct Item {
    int pos;
    ll amount;
};

bool item_sort(Item &a, Item &b) {
    return a.pos < b.pos;
}

int find_bigger_inclusive(vector<Item> &arr, int pos) {
    int start = 0;
    int end = arr.size() - 1;
    int mid;

    while (start <= end) {
        mid = (start + end) / 2;

        if (arr[mid].pos >= pos) {
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }

    return start;
}

int find_smaller_inclusive(vector<Item> &arr, int pos) {
    int start = 0;
    int end = arr.size() - 1;
    int mid;

    while (start <= end) {
        mid = (start + end) / 2;

        if (arr[mid].pos <= pos) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }

    return end;
}

vector<Item> row_items[MAX + 1];
vector<Item> col_items[MAX + 1];
vector<ll> row_prefix[MAX + 1];
vector<ll> col_prefix[MAX + 1];
vector<ll> row_prefix_rev[MAX + 1];
vector<ll> col_prefix_rev[MAX + 1];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N, Q;
    cin >> N >> Q;

    for (int i = 1; i <= N; i++) {
        int r, c, t;
        cin >> r >> c >> t;

        row_items[r].push_back({c, t});
        col_items[c].push_back({r, t});
    }

    for (int i = 1; i <= MAX; i++) {
        row_items[i].push_back({0, 0});
        row_items[i].push_back({MAX + 1, 0});

        sort(row_items[i].begin(), row_items[i].end(), item_sort);
    }

    for (int i = 1; i <= MAX; i++) {
        col_items[i].push_back({0, 0});
        col_items[i].push_back({MAX + 1, 0});

        sort(col_items[i].begin(), col_items[i].end(), item_sort);
    }

    for (int i = 1; i <= MAX; i++) {
        row_prefix[i].resize(row_items[i].size());
        col_prefix[i].resize(col_items[i].size());
        row_prefix_rev[i].resize(row_items[i].size());
        col_prefix_rev[i].resize(col_items[i].size());

        for (size_t j = 1; j < row_prefix[i].size(); j++) {
            row_prefix[i][j] = row_prefix[i][j - 1] + row_items[i][j].amount;
        }

        for (size_t j = 1; j < col_prefix[i].size(); j++) {
            col_prefix[i][j] = col_prefix[i][j - 1] + col_items[i][j].amount;
        }

        for (int j = row_prefix_rev[i].size() - 2; j >= 0; j--) {
            row_prefix_rev[i][j] = row_prefix_rev[i][j + 1] + row_items[i][j].amount;
        }

        for (int j = col_prefix_rev[i].size() - 2; j >= 0; j--) {
            col_prefix_rev[i][j] = col_prefix_rev[i][j + 1] + col_items[i][j].amount;
        }
    }

    int cur_r = 1;
    int cur_c = 1;
    ll score = 0;

    while (Q--) {
        int direction, dist, start, end, next_r, next_c;
        cin >> direction >> dist;

        switch (direction) {
            case 0:
                next_r = cur_r + dist;
                start = find_smaller_inclusive(col_items[cur_c], cur_r);
                end = find_smaller_inclusive(col_items[cur_c], next_r);

                score += col_prefix[cur_c][end] - col_prefix[cur_c][start];
                cur_r = next_r;
                break;
            case 1:
                next_c = cur_c + dist;
                start = find_smaller_inclusive(row_items[cur_r], cur_c);
                end = find_smaller_inclusive(row_items[cur_r], next_c);

                score += row_prefix[cur_r][end] - row_prefix[cur_r][start];
                cur_c = next_c;
                break;
            case 2:
                next_r = cur_r - dist;
                start = find_bigger_inclusive(col_items[cur_c], next_r);
                end = find_bigger_inclusive(col_items[cur_c], cur_r);

                score += col_prefix_rev[cur_c][start] - col_prefix_rev[cur_c][end];
                cur_r = next_r;
                break;
            case 3:
                next_c = cur_c - dist;
                start = find_bigger_inclusive(row_items[cur_r], next_c);
                end = find_bigger_inclusive(row_items[cur_r], cur_c);

                score += row_prefix_rev[cur_r][start] - row_prefix_rev[cur_r][end];
                cur_c = next_c;
                break;
        }
    }

    cout << score;
}