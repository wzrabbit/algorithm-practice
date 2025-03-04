#include <iostream>
#define MAX 100'000'000'000'000'000
typedef long long ll;
using namespace std;

ll get_digit_count(ll number) {
    ll digit_count = 0;

    while (number > 0) {
        digit_count += 1;
        number /= 10;
    }

    return digit_count;
}

ll get_fizz_buzz_length(ll number) {
    ll fizz_buzz_length = number / 3 * 4 + number / 5 * 4;

    ll range_start = 1;
    ll range_end = 9;
    ll digit_count = get_digit_count(number);

    for (ll i = 2; i <= digit_count; i++) {
        range_start *= 10;
        range_end = range_end * 10 + 9;
        range_end = min(range_end, number);

        ll range_number_count = range_end - range_start + 1;
        range_number_count -= range_number_count / 3 +
                              (range_number_count + 4) / 5 -
                              (range_number_count + 9) / 15;
        fizz_buzz_length += range_number_count * i;
    }

    for (ll i = 1; i <= min(9ll, number); i++) {
        if (i % 3 != 0 && i % 5 != 0) {
            fizz_buzz_length += 1;
        }
    }

    return fizz_buzz_length;
}

string get_nth_number_text(ll number) {
    if (number % 3 == 0 && number % 5 == 0) {
        return "FizzBuzz";
    }

    if (number % 3 == 0) {
        return "Fizz";
    }

    if (number % 5 == 0) {
        return "Buzz";
    }

    return to_string(number);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll N;
    cin >> N;

    ll start = 0;
    ll end = MAX;
    ll mid;

    while (start <= end) {
        mid = (start + end) / 2;
        ll fizz_buzz_length = get_fizz_buzz_length(mid);

        if (fizz_buzz_length < N) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }

    ll gap = N - get_fizz_buzz_length(end) - 1;
    string result_string = "";

    for (ll i = end + 1; i <= end + 20; i++) {
        result_string += get_nth_number_text(i);
    }

    for (size_t i = gap; i < gap + 20; i++) {
        cout << result_string[i];
    }
}
