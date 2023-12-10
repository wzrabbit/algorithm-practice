#include <iostream>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N;
    cin >> N;

    int popularity = 0;

    for (int i = 1; i <= N; i++) {
        int p, c;
        cin >> p >> c;

        if (p - c <= popularity && popularity <= p + c) {
            popularity += 1;
        }
    }

    cout << popularity;
}
