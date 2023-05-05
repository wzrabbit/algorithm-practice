#include <algorithm>
#include <iostream>
typedef long long ll;
using namespace std;

int backup[100001];
int num[100000];
int answer[100000];
int N, P;

bool is_possible(int gap) {
    for (int i = 1; i <= N; i++) {
        num[i] = backup[i];
    }

    ll chance = P;

    for (int i = 1; i <= N - 1; i++) {
        if (num[i] < num[i + 1] && num[i + 1] - num[i] > gap) {
            int cost = num[i + 1] - num[i] - gap;
            chance -= cost;
            num[i + 1] -= cost;
        }
    }

    for (int i = N; i >= 2; i--) {
        if (num[i] < num[i - 1] && num[i - 1] - num[i] > gap) {
            int cost = num[i - 1] - num[i] - gap;
            chance -= cost;
            num[i - 1] -= cost;
        }
    }

    if (chance < 0) {
        return false;
    }

    for (int i = 1; i <= N; i++) {
        answer[i] = num[i];
    }

    return true;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N >> P;

    for (int i = 1; i <= N; i++) {
        cin >> backup[i];
    }

    int start = 0;
    int end = 1'000'000'000;
    int mid;

    while (start <= end) {
        mid = (start + end) / 2;

        if (is_possible(mid)) {
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }

    for (int i = 1; i <= N; i++) {
        cout << answer[i] << ' ';
    }
}