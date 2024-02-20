#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int numbers[10];
int number_count[1001];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int sum = 0;
    int mode = 0;
    int mode_count = 0;

    for (int i = 0; i < 10; i++) {
        cin >> numbers[i];
        sum += numbers[i];
        number_count[numbers[i]] += 1;
    }

    int average = sum / 10;

    for (int i = 10; i <= 1000; i += 10) {
        if (number_count[i] > mode_count) {
            mode = i;
            mode_count = number_count[i];
        }
    }

    cout << average << '\n'
         << mode;
}
