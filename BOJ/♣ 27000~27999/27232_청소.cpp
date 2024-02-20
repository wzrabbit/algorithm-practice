#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
typedef long long ll;
using namespace std;

ll arr[500001];
ll positions[500001];
ll minimum_dist, current_dist;
set<ll> included_places;

void set_init_dist(vector<pair<ll, ll>> &init_arr) {
    ll init_dist = 0;

    for (size_t i = 1; i < init_arr.size(); i++) {
        init_dist += abs(init_arr[i - 1].second - init_arr[i].second);
    }

    minimum_dist = current_dist = init_dist;
}

ll get_dist(ll a, ll b) {
    if (a == -1 || b == -1) {
        return 0;
    }

    return abs(positions[a] - positions[b]);
}

ll get_left_element(ll element) {
    auto it = included_places.lower_bound(element);

    if (it == included_places.begin()) {
        return -1;
    }

    return *(--it);
}

ll get_right_element(ll element) {
    auto it = included_places.upper_bound(element);

    if (it == included_places.end()) {
        return -1;
    }

    return *it;
}

void remove_element(ll element) {
    ll left = get_left_element(element);
    ll right = get_right_element(element);

    current_dist -= get_dist(left, element);
    current_dist -= get_dist(right, element);
    current_dist += get_dist(left, right);

    included_places.erase(element);
}

void add_element(ll element) {
    included_places.insert(element);

    ll left = get_left_element(element);
    ll right = get_right_element(element);

    current_dist += get_dist(left, element);
    current_dist += get_dist(right, element);
    current_dist -= get_dist(left, right);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N, K;
    cin >> N >> K;

    vector<pair<ll, ll>> init_places;

    for (int i = 1; i <= N; i++) {
        cin >> arr[i];

        positions[arr[i]] = i;

        if (i <= K) {
            included_places.insert(arr[i]);
            init_places.push_back({arr[i], i});
        }
    }

    sort(init_places.begin(), init_places.end());
    set_init_dist(init_places);

    for (int i = K + 1; i <= N; i++) {
        remove_element(arr[i - K]);
        add_element(arr[i]);

        minimum_dist = min(minimum_dist, current_dist);
    }

    cout << minimum_dist;
}
