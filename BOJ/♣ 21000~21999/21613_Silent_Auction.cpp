#include <iostream>
using namespace std;

string best_player;
int best_price = 0;

int main() {
    int N;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        string cur_player;
        int cur_price;

        cin >> cur_player >> cur_price;

        if (best_price < cur_price) {
            best_price = cur_price;
            best_player = cur_player;
        }
    }

    cout << best_player;
}