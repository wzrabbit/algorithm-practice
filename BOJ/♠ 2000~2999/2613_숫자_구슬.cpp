#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int arr[301];
int N, M;

int is_possible(int limit) {
    int sum = 0;
    int pack_count = 1;

    for (int i = 1; i <= N; i++) {
        if (arr[i] > limit) {
            return false;
        }

        if (sum + arr[i] > limit) {
            pack_count += 1;
            sum = arr[i];
        } else {
            sum += arr[i];
        }
    }

    return pack_count <= M;
}

void print_distribution(int answer_limit) {
    int sum = 0;
    int cnt = 0;
    vector<int> answer;

    for (int i = 1; i <= N; i++) {
        if (sum + arr[i] > answer_limit) {
            answer.push_back(cnt);
            cnt = 0;
            sum = 0;
        }

        sum += arr[i];
        cnt += 1;
    }

    answer.push_back(cnt);

    int gap = M - answer.size();

    for (int i = 1; i <= gap; i++) {
        cout << 1 << ' ';
    }

    for (size_t i = 0; i < answer.size(); i++) {
        if (gap > 0) {
            int matched = min(gap, answer[i] - 1);
            gap -= matched;
            cout << answer[i] - matched << ' ';
        } else {
            cout << answer[i] << ' ';
        }
    }
}

int main() {
    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }

    int start = 1;
    int end = 30000;
    int mid;

    while (start <= end) {
        mid = (start + end) / 2;

        if (is_possible(mid)) {
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }

    cout << start << '\n';
    print_distribution(start);
}
