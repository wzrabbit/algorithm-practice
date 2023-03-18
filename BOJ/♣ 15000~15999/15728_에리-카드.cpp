#include <iostream>
#define INF 200'000'000
using namespace std;

int public_cards[100];
int team_cards[100];
bool is_banned[100];
int N, K;

void remove_best_card() {
    int best_card_index = -1;
    int best_card_score = -INF;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (is_banned[j]) continue;

            int current_score = public_cards[i] * team_cards[j];

            if (current_score > best_card_score) {
                best_card_index = j;
                best_card_score = current_score;
            }
        }
    }

    is_banned[best_card_index] = true;
}

int get_best_score() {
    int best_card_score = -INF;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (is_banned[j]) continue;

            int current_score = public_cards[i] * team_cards[j];
            best_card_score = max(best_card_score, current_score);
        }
    }

    return best_card_score;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N >> K;

    for (int i = 0; i < N; i++) {
        cin >> public_cards[i];
    }

    for (int i = 0; i < N; i++) {
        cin >> team_cards[i];
    }

    while (K--) {
        remove_best_card();
    }

    cout << get_best_score();
}