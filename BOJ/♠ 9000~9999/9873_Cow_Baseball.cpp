#include <algorithm>
#include <iostream>
using namespace std;

int cow[1001];
int N;

int binary_search(int one, int two) {
    int gap = cow[two] - cow[one];
    int start = two + 1;
    int end = N;
    int mid;
    int minus = 0;

    while (start <= end) {
        mid = (start + end) / 2;

        if (cow[mid] - cow[two] < gap) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }
    minus += end - two;

    start = two + 1;
    end = N;

    while (start <= end) {
        mid = (start + end) / 2;

        if (cow[mid] - cow[two] > gap * 2) {
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }
    minus += N - start + 1;

    return N - two - minus;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N;
    int count = 0;

    for (int i = 1; i <= N; i++) {
        cin >> cow[i];
    }

    sort(&cow[1], &cow[N + 1]);

    for (int i = 1; i <= N - 2; i++) {
        for (int j = i + 1; j <= N - 1; j++) {
            count += binary_search(i, j);
        }
    }

    cout << count;
}