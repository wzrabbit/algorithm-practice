#include <algorithm>
#include <iostream>
using namespace std;

// Query - ? s a b : s번째 봉우리에서 a번 탐지기, b개 검사

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N;
    cin >> N;
    int maximum;

    cout << "? 1 1 " << N << endl;
    cin >> maximum;

    int best_index = 1;
    int detector_gap = 2;

    while (true) {
        if (best_index + detector_gap / 2 > N) {
            cout << "! " << best_index << endl;
            break;
        }

        int check_index = best_index + detector_gap / 2;
        int check_count = (N - check_index) / detector_gap + 1;
        int detector_gap_no_overflow = min(detector_gap, N);

        cout << "? " << check_index << ' ' << detector_gap_no_overflow << ' ' << check_count << endl;

        int response;
        cin >> response;

        if (response == maximum) {
            best_index += detector_gap / 2;
        }

        detector_gap *= 2;
    }
}