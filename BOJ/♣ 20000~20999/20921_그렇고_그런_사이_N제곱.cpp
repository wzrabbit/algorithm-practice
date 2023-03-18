#include <algorithm>
#include <iostream>
using namespace std;

int numbers[4243];
int N, K;

void fill_numbers() {
    for (int i = 1; i <= N; i++) {
        numbers[i] = i;
    }
}

void make_soso_relationship() {
    for (int i = 1; i <= N - 1; i++) {
        for (int j = N - 1; j >= i; j--) {
            if (K <= 0) return;

            swap(numbers[j], numbers[j + 1]);
            K -= 1;
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N >> K;

    fill_numbers();
    make_soso_relationship();

    for (int i = 1; i <= N; i++) {
        cout << numbers[i] << ' ';
    }
}