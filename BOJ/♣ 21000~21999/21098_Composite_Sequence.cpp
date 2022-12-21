#include <iostream>
using namespace std;

int nums[3];

bool is_prime(int num) {
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int N;
    cin >> N;

    if (N >= 4) {
        cout << "Yes";
        return 0;
    }

    for (int i = 0; i < N; i++) {
        cin >> nums[i];
    }

    switch (N) {
        case 1:
            if (is_prime(nums[0])) {
                cout << "No";
            } else {
                cout << "Yes";
            }
            break;

        case 2:
            if (is_prime(nums[0]) && is_prime(nums[1]) && is_prime(nums[0] + nums[1])) {
                cout << "No";
            } else {
                cout << "Yes";
            }
            break;

        case 3:
            if (nums[0] == 1 && nums[1] == 1 && nums[2] == 1) {
                cout << "No";
            } else {
                cout << "Yes";
            }
            break;
    }
}