#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
#define SIEVE_SQRT 2240
#define MAX_SIZE 5000000
typedef long long ll;
using namespace std;

bool is_not_prime[MAX_SIZE];
bool is_already_spoken[MAX_SIZE];
priority_queue<int> player_primes[2];
ll scores[2];

void fill_sieve() {
    is_not_prime[0] = true;
    is_not_prime[1] = true;

    for (int i = 2; i <= SIEVE_SQRT; i++) {
        if (is_not_prime[i]) continue;

        for (int j = i * 2; j < MAX_SIZE; j += i) {
            is_not_prime[j] = true;
        }
    }
}

void give_spoken_score(int opponent_no) {
    if (player_primes[opponent_no].size() >= 3) {
        vector<int> temp_primes;
        for (int i = 0; i < 3; i++) {
            int popped_prime = player_primes[opponent_no].top();
            temp_primes.push_back(popped_prime);
            player_primes[opponent_no].pop();
        }

        scores[opponent_no] += temp_primes[2];

        for (int i = 0; i < 3; i++) {
            player_primes[opponent_no].push(temp_primes[i]);
        }
    } else {
        scores[opponent_no] += 1000;
    }
}

void add_number(int player_no, int number) {
    player_primes[player_no].push(number);
    is_already_spoken[number] = true;
}

void do_round(int player_no, int number) {
    if (is_not_prime[number]) {
        int opponent_no = 1 - player_no;
        give_spoken_score(opponent_no);
        return;
    }

    if (is_already_spoken[number]) {
        scores[player_no] -= 1000;
        return;
    }

    add_number(player_no, number);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N;
    cin >> N;

    fill_sieve();

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 2; j++) {
            int cur_number;
            cin >> cur_number;
            do_round(j, cur_number);
        }
    }

    if (scores[0] > scores[1])
        cout << "소수의 신 갓대웅";
    else if (scores[0] < scores[1])
        cout << "소수 마스터 갓규성";
    else
        cout << "우열을 가릴 수 없음";
}