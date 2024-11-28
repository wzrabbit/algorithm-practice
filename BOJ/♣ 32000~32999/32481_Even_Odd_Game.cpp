#include <iostream>
#include <set>
#define NO_EFFECT 1
#define INVERT 2
#define FIX 3
#define UNKNOWN 0
#define WIN 1
#define LOSE 2
#define FIRST 1
#define SECOND 2
using namespace std;

struct Card {
    char opr;
    int num;
};

bool operator<(const Card& a, const Card& b) {
    if (a.opr != b.opr) {
        return a.opr < b.opr;
    }

    return a.num < b.num;
};

int dp[301][301][301][2];
int next_card_type[301][301][301][2];
set<Card> no_effect_cards, invert_cards, fix_cards;
int N, start_value;

bool top_down(int no_effect_count, int invert_count, int fix_count, bool is_odd) {
    int& cur = dp[no_effect_count][invert_count][fix_count][is_odd];
    int& next_type = next_card_type[no_effect_count][invert_count][fix_count][is_odd];

    if (cur != UNKNOWN) {
        return cur == WIN;
    }

    int left_card_count = no_effect_count + invert_count + fix_count;
    int turn = ((N - left_card_count) % 2 == 1) ? SECOND : FIRST;

    if (left_card_count == 0) {
        if (turn == FIRST) {
            cur = (is_odd) ? WIN : LOSE;
        } else {
            cur = (is_odd) ? LOSE : WIN;
        }

        return cur == WIN;
    }

    cur = LOSE;

    if (no_effect_count >= 1 && !top_down(no_effect_count - 1, invert_count, fix_count, is_odd)) {
        cur = WIN;
        next_type = NO_EFFECT;
    }

    if (invert_count >= 1 && !top_down(no_effect_count, invert_count - 1, fix_count, !is_odd)) {
        cur = WIN;
        next_type = INVERT;
    }

    if (fix_count >= 1 && !top_down(no_effect_count, invert_count, fix_count - 1, false)) {
        cur = WIN;
        next_type = FIX;
    }

    return cur == WIN;
}

void interact() {
    int no_effect_card_count = no_effect_cards.size();
    int invert_card_count = invert_cards.size();
    int fix_card_count = fix_cards.size();
    bool is_odd = start_value % 2;
    bool is_player_turn = top_down(no_effect_card_count, invert_card_count, fix_card_count, is_odd);

    if (is_player_turn) {
        cout << "me" << endl;
    } else {
        cout << "you" << endl;
    }

    while (no_effect_card_count + invert_card_count + fix_card_count > 0) {
        if (is_player_turn) {
            int next_type = next_card_type[no_effect_card_count][invert_card_count][fix_card_count][is_odd];

            if (next_type == NO_EFFECT) {
                cout << no_effect_cards.begin()->opr << ' ' << no_effect_cards.begin()->num << endl;
                no_effect_card_count -= 1;
                no_effect_cards.erase(no_effect_cards.begin());
            } else if (next_type == INVERT) {
                cout << invert_cards.begin()->opr << ' ' << invert_cards.begin()->num << endl;
                invert_card_count -= 1;
                is_odd = !is_odd;
                invert_cards.erase(invert_cards.begin());
            } else {
                cout << fix_cards.begin()->opr << ' ' << fix_cards.begin()->num << endl;
                fix_card_count -= 1;
                is_odd = false;
                fix_cards.erase(fix_cards.begin());
            }
        } else {
            char opr;
            int num;
            cin >> opr >> num;

            if (no_effect_cards.find({opr, num}) != no_effect_cards.end()) {
                no_effect_cards.erase({opr, num});
                no_effect_card_count -= 1;
            }

            if (invert_cards.find({opr, num}) != invert_cards.end()) {
                invert_cards.erase({opr, num});
                invert_card_count -= 1;
                is_odd = !is_odd;
            }

            if (fix_cards.find({opr, num}) != fix_cards.end()) {
                fix_cards.erase({opr, num});
                fix_card_count -= 1;
                is_odd = false;
            }
        }

        is_player_turn = !is_player_turn;
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N;

    for (int i = 1; i <= N; i++) {
        char opr;
        int num;
        cin >> opr >> num;

        if (opr == '+') {
            if (num % 2 == 0) {
                no_effect_cards.insert({opr, num});
            } else {
                invert_cards.insert({opr, num});
            }
            continue;
        }

        if (num % 2 == 0) {
            fix_cards.insert({opr, num});
        } else {
            no_effect_cards.insert({opr, num});
        }
    }

    cin >> start_value;

    interact();
}
