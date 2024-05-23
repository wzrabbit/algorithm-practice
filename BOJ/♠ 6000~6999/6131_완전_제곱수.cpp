#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;

    int answer = 0;

    for (int a = 1; a <= N; a++) {
        for (int b = a; b <= N; b++) {
            if (b * b - a * a == N) {
                answer += 1;
            }
        }
    }

    cout << answer;
}
