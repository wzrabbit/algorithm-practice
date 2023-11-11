#include <iostream>
using namespace std;

int arr[5];

int main() {
    for (int i = 0; i < 5; i++) {
        cin >> arr[i];
    }

    int num = 1;

    while (true) {
        int multiple_count = 0;

        for (int i = 0; i < 5; i++) {
            if (num % arr[i] == 0) {
                multiple_count += 1;
            }
        }

        if (multiple_count >= 3) {
            cout << num;
            return 0;
        }

        num += 1;
    }
}