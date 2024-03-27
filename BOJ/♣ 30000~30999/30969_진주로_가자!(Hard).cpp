#include <iostream>
#include <string>
typedef long long ll;
using namespace std;

int cost[1002];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N;
    cin >> N;

    int jinju_cost = 0;

    for (int i = 1; i <= N; i++) {
        string name;
        ll cur_cost;

        cin >> name >> cur_cost;

        if (name == "jinju") {
            jinju_cost = cur_cost;
        } else {
            cost[min(1001ll, cur_cost)] += 1;
        }
    }

    int answer = 0;

    for (int i = jinju_cost + 1; i <= 1001; i++) {
        answer += cost[i];
    }

    cout << jinju_cost << '\n'
         << answer;
}
