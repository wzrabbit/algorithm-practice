#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

int arr[100'001];
int dp[3'000'001];
vector<int> fibonacci;

void make_fibonacci(int limit) {
    fibonacci.push_back(1);
    fibonacci.push_back(2);

    while (true) {
        int a = fibonacci[fibonacci.size() - 2];
        int b = fibonacci[fibonacci.size() - 1];

        if (a + b > limit) {
            break;
        }

        fibonacci.push_back(a + b);
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }

    make_fibonacci(3'000'000);

    for (int i = 0; i <= 3'000'000; i++) {
        vector<bool> grundy_numbers(20);

        for (int j = 0; j < fibonacci.size(); j++) {
            if (i - fibonacci[j] < 0) {
                break;
            }

            grundy_numbers[dp[i - fibonacci[j]]] = true;
        }

        for (size_t j = 0; j < 20; j++) {
            if (!grundy_numbers[j]) {
                dp[i] = j;
                break;
            }
        }
    }

    int xor_value = 0;

    for (int i = 1; i <= N; i++) {
        xor_value ^= dp[arr[i]];
    }

    if (xor_value == 0) {
        cout << "cubelover";
    } else {
        cout << "koosaga";
    }
}
