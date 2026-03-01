#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

struct Query {
    int a, b, c;
};

int arr[1000001];
int prefix[2][500002];
vector<Query> queries;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> arr[i];

        prefix[(i - 1) % 2][(i - 1) / 2 + 1] += arr[i];
        prefix[(i - 1) % 2][(i - 1) / 2 + 2] += arr[i];
    }

    for (int i = 0; i < 2; i++) {
        for (int j = 1; j <= N / 2 + 1; j++) {
            if (prefix[i][j] == 0 || j * 2 - 1 + i > N) continue;

            queries.push_back({j * 2 - 1 + i, prefix[i][j], 3});
        }
    }

    cout << queries.size() << '\n';

    for (const auto& q : queries) {
        cout << q.a << ' ' << q.b << ' ' << q.c << '\n';
    }
}
