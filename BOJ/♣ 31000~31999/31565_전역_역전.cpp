#include <algorithm>
#include <iostream>
#include <queue>
#define INF 1'000'000'000'000
typedef long long ll;
using namespace std;

struct Date {
    int y, m, d;
};

struct Plan {
    ll cost, power;
};

ll month[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
Plan plans[101];
ll dp[101][10001];

bool check_leap(ll year) {
    if (year % 400 == 0) {
        return true;
    }

    return year % 4 == 0 && year % 100 != 0;
}

ll get_date_prefix(Date date) {
    ll sum = 0;
    bool is_leap = check_leap(date.y);

    for (int i = 1; i < date.m; i++) {
        if (i == 2) {
            if (is_leap) {
                sum += 29;
            } else {
                sum += 28;
            }
            continue;
        }

        sum += month[i];
    }

    sum += date.d - 1;

    return sum;
}

ll get_date_gap(Date a, Date b) {
    ll gap = 0;

    if (a.y == b.y) {
        return get_date_prefix(b) - get_date_prefix(a);
    }

    for (int i = a.y + 1; i < b.y; i++) {
        if (check_leap(i)) {
            gap += 366;
        } else {
            gap += 365;
        }
    }

    gap += get_date_prefix({a.y, 12, 31}) - get_date_prefix(a) + 1;
    gap += get_date_prefix(b) - get_date_prefix({b.y, 1, 1});

    return gap;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    Date me, enemy;
    ll time, N;

    cin >> me.y >> me.m >> me.d;
    cin >> enemy.y >> enemy.m >> enemy.d;
    cin >> time >> N;

    for (int i = 1; i <= N; i++) {
        ll a, b, c;
        cin >> a >> b >> c;

        if (a == 3) {
            plans[i] = {b, c * 30};
        } else {
            plans[i] = {b, abs(c)};
        }
    }

    fill(&dp[0][0], &dp[N][10001], -INF);
    dp[0][0] = 0;

    for (int r = 1; r <= N; r++) {
        for (int c = 0; c <= time; c++) {
            dp[r][c] = dp[r - 1][c];

            if (plans[r].cost <= c) {
                dp[r][c] = max(dp[r][c], dp[r - 1][c - plans[r].cost] + plans[r].power);
            }
        }
    }

    ll best_decrease = 0;

    for (int i = 0; i <= time; i++) {
        best_decrease = max(best_decrease, dp[N][i]);
    }

    ll gap = get_date_gap(me, enemy);
    cout << abs(gap - best_decrease);
}
