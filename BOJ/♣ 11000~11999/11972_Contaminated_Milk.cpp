#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

struct Info {
    int n, t;
};

vector<Info> drink_infos[51];
bool is_bad_milk[51];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N, M, D, S;
    cin >> N >> M >> D >> S;

    for (int i = 1; i <= D; i++) {
        int person, milk_no, time;
        cin >> person >> milk_no >> time;

        drink_infos[person].push_back({milk_no, time});
    }

    fill(is_bad_milk + 1, is_bad_milk + M + 1, true);

    for (int i = 1; i <= S; i++) {
        int person, sick_time;
        cin >> person >> sick_time;

        vector<int> is_innocent_milk(M + 1, true);

        for (size_t j = 0; j < drink_infos[person].size(); j++) {
            int cur_milk_no = drink_infos[person][j].n;
            int cur_time = drink_infos[person][j].t;

            if (cur_time < sick_time) {
                is_innocent_milk[cur_milk_no] = false;
            }
        }

        for (int i = 1; i <= M; i++) {
            if (is_innocent_milk[i]) {
                is_bad_milk[i] = false;
            }
        }
    }

    int max_sick_count = 0;

    for (int i = 1; i <= M; i++) {
        if (!is_bad_milk[i]) {
            continue;
        }

        int sick_count = 0;

        for (int j = 1; j <= N; j++) {
            bool is_sick = false;

            for (size_t k = 0; k < drink_infos[j].size(); k++) {
                if (drink_infos[j][k].n == i) {
                    is_sick = true;
                    break;
                }
            }

            if (is_sick) {
                sick_count += 1;
            }
        }

        max_sick_count = max(max_sick_count, sick_count);
    }

    cout << max_sick_count;
}
