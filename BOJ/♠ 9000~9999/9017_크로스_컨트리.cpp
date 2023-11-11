#include <algorithm>
#include <iostream>
#define INF 9876
using namespace std;

int arr[1001];
int team_four_score[201];
int team_five_score[201];
int member_count[201];
int plus_count[201];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        fill(team_four_score + 1, team_four_score + 201, 0);
        fill(team_five_score + 1, team_five_score + 201, 0);
        fill(member_count + 1, member_count + 201, 0);
        fill(plus_count + 1, plus_count + 201, 0);

        for (int i = 1; i <= N; i++) {
            cin >> arr[i];
            member_count[arr[i]] += 1;
        }

        int cur_rank = 0;

        for (int i = 1; i <= N; i++) {
            int team = arr[i];

            if (member_count[team] != 6) {
                continue;
            }

            cur_rank += 1;
            plus_count[team] += 1;

            if (plus_count[team] <= 4) {
                team_four_score[team] += cur_rank;
            }

            if (plus_count[team] == 5) {
                team_five_score[team] = cur_rank;
            }
        }

        int winner = 0;
        int winner_four_score = INF;
        int winner_five_score = INF;

        for (int i = 1; i <= 200; i++) {
            if (member_count[i] != 6) {
                continue;
            }

            if (team_four_score[i] > winner_four_score) {
                continue;
            }

            if (team_four_score[i] < winner_four_score ||
                team_five_score[i] < winner_five_score) {
                winner = i;
                winner_four_score = team_four_score[i];
                winner_five_score = team_five_score[i];
            }
        }

        cout << winner << '\n';
    }
}