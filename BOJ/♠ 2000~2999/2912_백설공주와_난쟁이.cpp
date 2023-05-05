#include <algorithm>
#include <ctime>
#include <iostream>
#include <vector>
#define REPEAT 50
using namespace std;

int raw[300001];
vector<int> colors[10001];

int get_color_count(int color_no, int left, int right) {
    int start = 0;
    int end = colors[color_no].size() - 1;
    int mid;

    while (start <= end) {
        int mid = (start + end) / 2;
        if (colors[color_no][mid] >= left) {
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }

    int ans_start = end;

    start = 0;
    end = colors[color_no].size() - 1;

    while (start <= end) {
        int mid = (start + end) / 2;
        if (colors[color_no][mid] <= right) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }

    int ans_end = start;

    return ans_end - ans_start - 1;
}

void check_valid(int start, int end) {
    for (int i = 1; i <= REPEAT; i++) {
        int selected = raw[rand() % (end - start + 1) + start];
        int all = end - start + 1;
        int cur = 0;

        if (get_color_count(selected, start, end) * 2 > all) {
            cout << "yes " << selected << '\n';
            return;
        }
    }

    cout << "no\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    srand(time(NULL));

    int N, _;
    cin >> N >> _;

    for (int i = 1; i <= N; i++) {
        cin >> raw[i];
        colors[raw[i]].push_back(i);
    }

    int Q;
    cin >> Q;

    while (Q--) {
        int start, end;
        cin >> start >> end;
        check_valid(start, end);
    }
}