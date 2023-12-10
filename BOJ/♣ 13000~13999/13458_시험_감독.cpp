#include <algorithm>
#include <iostream>
typedef long long ll;
using namespace std;

ll arr[1000001];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }

    ll B, C;
    cin >> B >> C;

    ll answer = N;

    for (int i = 1; i <= N; i++) {
        if (arr[i] <= B) {
            continue;
        }

        if ((arr[i] - B) % C == 0) {
            answer += (arr[i] - B) / C;
        } else {
            answer += (arr[i] - B) / C + 1;
        }
    }

    cout << answer;
}
