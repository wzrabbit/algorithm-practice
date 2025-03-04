#include <iostream>
using namespace std;

int turn_speed = 4;
int turn_score = 1;
int score = 0;
int elapsed_time = 0;
int prizes[5];

void end_game() {
    if (score >= 125) {
        prizes[4] += 1;
    } else if (score >= 95) {
        prizes[3] += 1;
    } else if (score >= 65) {
        prizes[2] += 1;
    } else if (score >= 35) {
        prizes[1] += 1;
    }

    turn_speed = 4;
    turn_score = 1;
    score = 0;
    elapsed_time = 0;
}

void perform_1() { end_game(); }

void perform_2() {
    if (turn_score > 1) {
        turn_score /= 2;
        return;
    }

    turn_speed += 2;
}

void perform_3() {
    // 아무고또 모타죠
}

void perform_4() { elapsed_time += 56; }

void perform_5() {
    if (turn_speed > 1) {
        turn_speed -= 1;
    }
}

void perform_6() {
    if (turn_score < 32) {
        turn_score *= 2;
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        int dice;
        cin >> dice;

        if (elapsed_time > 240) {
            end_game();
        }

        switch (dice) {
            case 1:
                perform_1();
                break;
            case 2:
                perform_2();
                break;
            case 3:
                perform_3();
                break;
            case 4:
                perform_4();
                break;
            case 5:
                perform_5();
                break;
            case 6:
                perform_6();
                break;
        }

        if (dice != 1) {
            score += turn_score;
            elapsed_time += turn_speed;
        }
    }

    for (int i = 1; i <= 4; i++) {
        cout << prizes[i] << '\n';
    }
}
