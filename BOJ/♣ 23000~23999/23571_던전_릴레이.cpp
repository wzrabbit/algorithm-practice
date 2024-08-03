#include <algorithm>
#include <iostream>
typedef long long ll;
#define INF 1'000'000'000'000'000'000
using namespace std;

struct Dungeon {
    ll i, d, c, r;
};

struct Range {
    ll s, e;
};

bool operator<(const Dungeon &a, const Dungeon &b) {
    if (a.d != b.d) {
        return a.d < b.d;
    }

    return a.i < b.i;
}

Dungeon dungeons[100001];
ll real_index[100001];
ll min_arr[100001];
ll min_seg[400001];
ll min_lazy[400001];
ll sum_arr[400001];
ll sum_seg[400001];
int N;

void make_init_arr() {
    min_arr[1] = -dungeons[1].c;

    for (int i = 2; i <= N; i++) {
        min_arr[i] = min_arr[i - 1] + dungeons[i - 1].r - dungeons[i].c;
    }

    for (int i = 1; i <= N; i++) {
        sum_arr[i] = dungeons[i].r - dungeons[i].c;
    }
}

ll init_min_seg(ll start, ll end, ll index) {
    if (start == end) {
        return min_seg[index] = min_arr[start];
    }

    ll mid = (start + end) / 2;

    return min_seg[index] = min(
               init_min_seg(start, mid, index * 2),
               init_min_seg(mid + 1, end, index * 2 + 1));
}

ll init_sum_seg(ll start, ll end, ll index) {
    if (start == end) {
        return sum_seg[index] = sum_arr[start];
    }

    ll mid = (start + end) / 2;

    return sum_seg[index] =
               init_sum_seg(start, mid, index * 2) +
               init_sum_seg(mid + 1, end, index * 2 + 1);
}

void min_propagate(ll start, ll end, ll index) {
    if (min_lazy[index] == 0) {
        return;
    }

    min_seg[index] += min_lazy[index];

    if (start != end) {
        min_lazy[index * 2] += min_lazy[index];
        min_lazy[index * 2 + 1] += min_lazy[index];
    }

    min_lazy[index] = 0;
}

void min_update(ll start, ll end, ll index, ll left, ll right, ll value) {
    min_propagate(start, end, index);

    if (end < left || start > right) {
        return;
    }

    if (start >= left && end <= right) {
        min_seg[index] += value;

        if (start != end) {
            min_lazy[index * 2] += value;
            min_lazy[index * 2 + 1] += value;
        }

        return;
    }

    ll mid = (start + end) / 2;
    min_update(start, mid, index * 2, left, right, value);
    min_update(mid + 1, end, index * 2 + 1, left, right, value);
    min_seg[index] = min(min_seg[index * 2], min_seg[index * 2 + 1]);
}

void sum_update(ll start, ll end, ll index, ll target, ll value) {
    if (end < target || start > target) {
        return;
    }

    sum_seg[index] += value;

    if (start == end) {
        return;
    }

    ll mid = (start + end) / 2;
    sum_update(start, mid, index * 2, target, value);
    sum_update(mid + 1, end, index * 2 + 1, target, value);
}

ll get_min_value(ll start, ll end, ll index, ll left, ll right) {
    min_propagate(start, end, index);

    if (end < left || start > right) {
        return INF;
    }

    if (start >= left && end <= right) {
        return min_seg[index];
    }

    ll mid = (start + end) / 2;

    return min(
        get_min_value(start, mid, index * 2, left, right),
        get_min_value(mid + 1, end, index * 2 + 1, left, right));
}

ll get_sum(ll start, ll end, ll index, ll left, ll right) {
    if (end < left || start > right) {
        return 0;
    }

    if (start >= left && end <= right) {
        return sum_seg[index];
    }

    ll mid = (start + end) / 2;

    return get_sum(start, mid, index * 2, left, right) +
           get_sum(mid + 1, end, index * 2 + 1, left, right);
}

Range get_range_by_difficulty(ll min_difficulty, ll max_difficulty) {
    ll start = 1;
    ll end = N;
    ll mid;
    ll range_start, range_end;

    while (start <= end) {
        mid = (start + end) / 2;

        if (dungeons[mid].d >= min_difficulty) {
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }

    range_start = start;

    start = 1;
    end = N;

    while (start <= end) {
        mid = (start + end) / 2;

        if (dungeons[mid].d <= max_difficulty) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }

    range_end = end;

    if (range_start > range_end) {
        return {-1, -1};
    }

    return {range_start, range_end};
}

ll get_money(ll money, ll min_difficulty, ll max_difficulty) {
    Range range = get_range_by_difficulty(min_difficulty, max_difficulty);

    if (range.s == -1) {
        return -1;
    }

    ll min_value = get_min_value(1, N, 1, range.s, range.e);
    ll before_sum = get_sum(1, N, 1, 1, range.s - 1);
    bool is_possible = min_value - before_sum + money >= 0;
    ll result_money = get_sum(1, N, 1, range.s, range.e) + money;

    if (!is_possible) {
        return -1;
    }

    return result_money;
}

void update_cost(ll dungeon_no, ll cost) {
    ll real_dungeon_no = real_index[dungeon_no];
    ll diff = dungeons[real_dungeon_no].c - cost;

    min_update(1, N, 1, real_dungeon_no, N, diff);
    sum_update(1, N, 1, real_dungeon_no, diff);
    dungeons[real_dungeon_no].c = cost;
}

void update_reward(ll dungeon_no, ll reward) {
    ll real_dungeon_no = real_index[dungeon_no];
    ll diff = reward - dungeons[real_dungeon_no].r;

    min_update(1, N, 1, real_dungeon_no + 1, N, diff);
    sum_update(1, N, 1, real_dungeon_no, diff);
    dungeons[real_dungeon_no].r = reward;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N;

    for (int i = 1; i <= N; i++) {
        ll d, c, r;
        cin >> d >> c >> r;

        dungeons[i] = {i, d, c, r};
    }

    sort(dungeons + 1, dungeons + N + 1);

    for (int i = 1; i <= N; i++) {
        real_index[dungeons[i].i] = i;
    }

    make_init_arr();
    init_min_seg(1, N, 1);
    init_sum_seg(1, N, 1);

    int Q;
    cin >> Q;

    while (Q--) {
        int type;
        cin >> type;

        if (type == 1) {
            ll start_money, min_difficulty, max_difficulty;
            cin >> start_money >> min_difficulty >> max_difficulty;

            ll result_money = get_money(start_money, min_difficulty, max_difficulty);

            if (result_money == -1) {
                cout << -1 << '\n';
            } else {
                cout << 1 << ' ' << result_money << '\n';
            }

            continue;
        }

        if (type == 2) {
            ll dungeon_no, cost;
            cin >> dungeon_no >> cost;
            update_cost(dungeon_no, cost);

            continue;
        }

        ll dungeon_no, reward;
        cin >> dungeon_no >> reward;
        update_reward(dungeon_no, reward);
    }
}
