#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

char S[1000002];
int prefix[1000002];
int N;

int get_answer(int goal) {
    int answer = 0;
    int index = goal;

    while (true) {
        if (index > N) return answer;

        int need = goal - prefix[index];

        if (need == 0) {
            return answer + 1;
        }

        index += need;
        answer += 1;
    }

    return 0;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N >> (S + 1);

    for (int i = 1; i <= N; i++) {
        prefix[i] = prefix[i - 1] + (S[i] == 'S' ? 1 : 0);
    }

    for (int i = 1; i <= N; i++) {
        cout << get_answer(i) << ' ';
    }
}
