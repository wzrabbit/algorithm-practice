#include <iostream>
using namespace std;

bool visited[1000000];

int main() {
    int N;
    cin >> N;

    int digit_length = 0;
    int current_number = 0;
    bool success = true;

    while (true) {
        current_number = (current_number * 10 + 1) % N;
        digit_length += 1;

        if (visited[current_number]) {
            success = false;
            break;
        }

        visited[current_number] = true;

        if (visited[0]) {
            break;
        }
    }

    if (success) {
        cout << digit_length;
    } else {
        cout << -1;
    }
}