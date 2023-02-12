#include <algorithm>
#include <iostream>
using namespace std;

int numbers[100000];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> numbers[i];
    }

    sort(numbers, numbers + N);

    int direction = -1;
    int move_distance = 1;
    int current = N / 2;

    for (int i = 0; i < N; i++) {
        cout << numbers[current] << ' ';
        current += direction * move_distance;
        direction *= -1;
        move_distance += 1;
    }
}