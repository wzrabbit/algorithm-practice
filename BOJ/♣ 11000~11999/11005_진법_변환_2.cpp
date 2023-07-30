#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

string result;

char convert(int digit) {
    if (digit >= 10) return 'A' + digit - 10;
    return '0' + digit;
}

int main() {
    int N, B;
    bool is_zero_ren = true;
    cin >> N >> B;

    while (N > 0) {
        result += convert(N % B);
        N /= B;
    }

    reverse(result.begin(), result.end());

    for (size_t i = 0; i < result.size(); i++) {
        if (result[i] == '0' && is_zero_ren) {
            continue;
        }

        cout << result[i];
        is_zero_ren = false;
    }
}