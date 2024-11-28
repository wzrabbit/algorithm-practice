#include <iomanip>
#include <iostream>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N;
    cin >> N;

    int answer = 0;

    for (int i = 1; i <= N; i++) {
        int cur;
        cin >> cur;

        switch (cur) {
            case 0:
                answer += 32;
                break;
            case 1:
                answer += 16;
                break;
            case 2:
                answer += 8;
                break;
            case 4:
                answer += 4;
                break;
            case 8:
                answer += 2;
                break;
            case 16:
                answer += 1;
                break;
        }
    }

    cout << fixed << setprecision(7) << answer / 16.0;
}
