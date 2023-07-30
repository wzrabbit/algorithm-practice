#include <algorithm>
#include <iostream>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N, A, B;
    cin >> N >> A >> B;

    if (A > B) {
        swap(A, B);
    }

    int round_no = 1;

    while (A + 1 != B || A % 2 == 0) {
        A = A - A / 2;
        B = B - B / 2;

        round_no += 1;
    }

    cout << round_no;
}