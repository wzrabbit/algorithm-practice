#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int limits[200001];
vector<int> grow_data[200001];
int result[200001];

void make_result(int a, int b, int p, int K) {
    int required = limits[p];
    int start = 1;
    int end = K;
    int mid;

    while (start <= end) {
        mid = (start + end) / 2;
        int a_height = upper_bound(grow_data[a].begin(), grow_data[a].end(), mid) - grow_data[a].begin();
        int b_height = upper_bound(grow_data[b].begin(), grow_data[b].end(), mid) - grow_data[b].begin();

        if (a_height + b_height >= required) {
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }

    result[start] += 1;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N, M, K, Q;
    cin >> N >> M >> K >> Q;

    for (int i = 1; i <= M; i++) {
        cin >> limits[i];
    }

    for (int i = 1; i <= K; i++) {
        int cur;
        cin >> cur;

        grow_data[cur].push_back(i);
    }

    for (int i = 1; i <= Q; i++) {
        int a, b, p;
        cin >> a >> b >> p;

        make_result(a, b, p, K);
    }

    for (int i = 1; i <= K; i++) {
        result[i] += result[i - 1];
        cout << result[i] << '\n';
    }
}
