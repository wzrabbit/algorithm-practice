    #include <algorithm>
    #include <iostream>
    #include <set>
    #include <string>
    using namespace std;

    int convert_time_to_number(string time) {
        int hh = stoi(time.substr(0, 2));
        int mm = stoi(time.substr(3, 5));

        return (hh * 60 + mm) % 720;
    }

    int records[1501];

    int main() {
        cin.tie(0)->sync_with_stdio(0);

        int M;
        cin >> M;

        for (int i = 1; i <= M; i++) {
            string string_time;
            cin >> string_time;

            int numerized_time = convert_time_to_number(string_time);
            records[i] = numerized_time;
        }

        int N = M;

        for (int r = 1; r <= 720; r++) {
            set<int> clocks;
            int minus_time = records[1];
            clocks.insert(0);

            for (int i = 2; i <= M; i++) {
                minus_time = (minus_time + r) % 720;

                int real_time = (records[i] + 720 - minus_time) % 720;

                if (clocks.find(real_time) == clocks.end()) {
                    clocks.insert(real_time);
                }
            }

            N = min(N, (int)clocks.size());
        }

        cout << N;
    }