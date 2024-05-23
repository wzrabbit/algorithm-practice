#include <algorithm>
#include <iostream>
using namespace std;

int profit[300001];
int sorted_profit[300001];
int cost[300001];
int op_cost[300001];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> profit[i];
        sorted_profit[i] = profit[i];
    }

    for (int i = 1; i <= N; i++) {
        cin >> cost[i];
    }

    sort(sorted_profit + 1, sorted_profit + N + 1, greater<int>());

    for (int i = 1; i <= N; i++) {
        if (profit[i] == sorted_profit[1] && sorted_profit[1] != sorted_profit[2]) {
            op_cost[i] = sorted_profit[2] - cost[i];
            continue;
        }

        op_cost[i] = sorted_profit[1] - cost[i];
    }

    for (int i = 1; i <= N; i++) {
        cout << profit[i] - op_cost[i] - cost[i] << ' ';
    }
}
