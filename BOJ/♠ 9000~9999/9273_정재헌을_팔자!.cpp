#include <iostream>
using namespace std;

int main() {
    int N;

    while (scanf("1/%d\n", &N) != EOF) {
        int count = 0;

        for (int i = N + 1; i <= N * 2; i++) {
            if ((N * i) % (i - N) == 0) {
                count += 1;
            }
        }

        printf("%d\n", count);
    }
}