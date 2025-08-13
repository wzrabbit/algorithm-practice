#include <algorithm>
#include <iostream>
#include <string>
typedef long long ll;
using namespace std;

struct Date {
    ll year, month, day, hour, minute, second;
};

struct Fraction {
    ll u, d;
};

ll MONTHS[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
ll DAY_TIME = 86'400;

bool is_leap_year(ll year) {
    return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
}

Fraction add_fractions(Fraction a, Fraction b) {
    return {a.u * b.d + b.u * a.d, a.d * b.d};
}

ll get_time_value_from_zero(Date cur) {
    ll total_time = cur.hour * 3600 + cur.minute * 60 + cur.second;

    ll leap_year_count =
        (cur.year - 1) / 4 - (cur.year - 1) / 100 + (cur.year - 1) / 400;
    ll normal_year_count = cur.year - 1 - leap_year_count;
    ll total_day_count =
        leap_year_count * 366 + normal_year_count * 365 + cur.day - 1;

    for (int i = 1; i < cur.month; i++) {
        total_day_count += MONTHS[i];

        if (i == 2 && is_leap_year(cur.year)) {
            total_day_count += 1;
        }
    }

    total_time += total_day_count * DAY_TIME;

    return total_time;
}

ll get_time_value_by_range(Date start, Date end) {
    return get_time_value_from_zero(end) - get_time_value_from_zero(start);
}

Fraction get_year_fraction(Date start, Date end) {
    Fraction result;
    result.u = get_time_value_by_range(start, end);
    result.d = is_leap_year(start.year) ? 366 * DAY_TIME : 365 * DAY_TIME;

    return result;
}

Fraction get_month_fraction(Date start, Date end) {
    Fraction result;
    result.u = get_time_value_by_range(start, end);
    result.d = (MONTHS[start.month] +
                (start.month == 2 && is_leap_year(start.year) ? 1 : 0)) *
               DAY_TIME;

    return result;
}

ll solve(Date before, Date after, string mode) {
    if (mode == "Day") {
        return get_time_value_by_range(before, after) / DAY_TIME;
    }

    if (mode == "Year" && before.year == after.year) {
        return 0;
    }

    if (mode == "Month" && before.year == after.year &&
        before.month == after.month) {
        return 0;
    }

    if (mode == "Year") {
        ll full_year_count = after.year - before.year - 1;

        Date before_boundary = {before.year + 1, 1, 1, 0, 0, 0};
        Date after_boundary = {after.year, 1, 1, 0, 0, 0};
        Fraction year_fraction =
            add_fractions(get_year_fraction(before, before_boundary),
                          get_year_fraction(after_boundary, after));

        return full_year_count + year_fraction.u / year_fraction.d;
    }

    Date before_boundary = {before.year, before.month + 1, 1, 0, 0, 0};
    Date after_boundary = {after.year, after.month, 1, 0, 0, 0};

    if (before_boundary.month == 13) {
        before_boundary.year += 1;
        before_boundary.month = 1;
    }

    ll full_month_count =
        after.year * 12 + after.month - before.year * 12 - before.month - 1;

    Fraction month_fraction =
        add_fractions(get_month_fraction(before, before_boundary),
                      get_month_fraction(after_boundary, after));

    return full_month_count + month_fraction.u / month_fraction.d;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int T;
    cin >> T;

    while (T--) {
        Date before, after;
        string mode;
        cin >> before.year >> before.month >> before.day >> before.hour >>
            before.minute >> before.second;
        cin >> after.year >> after.month >> after.day >> after.hour >>
            after.minute >> after.second;
        cin >> mode;

        cout << solve(before, after, mode) << '\n';
    }
}
