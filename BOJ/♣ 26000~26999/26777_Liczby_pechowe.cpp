#include <iostream>
#include <string>
typedef long long ll;
using namespace std;

ll limit, sad_number_count;

ll get_digit_sum(ll number) {
    ll sum = 0;

    while (number > 0) {
        sum += number % 10;
        number /= 10;
    }

    return sum;
}

bool has_thirteen(ll number) {
    string S = to_string(number);
    for (size_t i = 0; i < S.size() - 1; i++) {
        if (S[i] == '1' && S[i + 1] == '3') {
            return true;
        }
    }

    return false;
}

bool is_invalid_number(ll number) {
    return (
        get_digit_sum(number) > 13 ||
        number > limit ||
        (get_digit_sum(number) == 13 && !has_thirteen(number)));
}

bool is_sad_number(ll number) {
    return get_digit_sum(number) == 13 && has_thirteen(number);
}

void back_tracking(ll cur_number) {
    if (is_invalid_number(cur_number)) {
        return;
    }

    if (is_sad_number(cur_number)) {
        sad_number_count += 1;
    }

    for (int i = 0; i <= 9; i++) {
        back_tracking(cur_number * 10 + i);
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> limit;

    for (int x = 1; x <= 9; x++) {
        back_tracking(x);
    }

    cout << sad_number_count;
}