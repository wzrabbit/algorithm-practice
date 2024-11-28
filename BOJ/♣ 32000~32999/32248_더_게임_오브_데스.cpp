#include <algorithm>
#include <iostream>
#include <vector>
typedef long long ll;
using namespace std;

int nxt[101];
vector<int> vec;
int first_index[101];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll N, T;
    cin >> N >> T;

    for (int i = 1; i <= N; i++) {
        cin >> nxt[i];
    }

    int cur_index = 1;
    vec.push_back(0);

    for (int i = 1; i <= 200; i++) {
        cur_index = nxt[cur_index];
        vec.push_back(cur_index);
    }

    ll cycle_start, cycle_size;

    for (int i = 1; i <= 200; i++) {
        int cur_number = vec[i];

        if (first_index[cur_number] == 0) {
            first_index[cur_number] = i;
            continue;
        }

        cycle_start = i;
        cycle_size = i - first_index[cur_number];
        break;
    }

    if (T < cycle_start) {
        cout << vec[T];
        return 0;
    }

    T -= cycle_start - 1;
    T %= cycle_size;

    cout << vec[cycle_start + T - 1];
}
