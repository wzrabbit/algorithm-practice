#include <algorithm>
#include <cmath>
#include <iostream>
typedef long long ll;
using namespace std;

int origin;
ll answer = 0;

int get_digit_sum(int number) {
    int total = 0;

    while (number > 0) {
        total += number % 10;
        total /= 10;
    }

    return total;
}

void find_current_digit(int level) {
    int start = 1;
    int end = 9;
    int mid;
    int after;

    while (start <= end) {
        mid = (start + end) / 2;
        cout << "query " << ll(pow(10, level)) * mid << endl;
        cin >> after;

        if (after == origin + mid) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }

    answer += (10 - start) * ll(pow(10, level));
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cout << "query 0" << endl;
    cin >> origin;

    for (int i = 0; i < 18; i++) {
        find_current_digit(i);
    }

    cout << "answer " << answer << endl;
}