#include <iostream>
typedef long long ll;
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        ll segment_sum = 0;
        ll positive_count = 0;
        ll negative_count = 0;

        for (int i = 1; i <= N; i++) {
            ll cur;
            cin >> cur;

            ll merged_segment_sum = segment_sum + cur;

            if (cur == 0) {
                continue;
            }

            if (segment_sum > 0) {
                if (cur > 0) {
                    positive_count += 1;
                    segment_sum = cur;
                }

                if (cur < 0) {
                    if (merged_segment_sum > 0) {
                        segment_sum = merged_segment_sum;
                        continue;
                    }

                    segment_sum = cur;
                    negative_count += 1;
                }

                continue;
            }

            if (segment_sum < 0) {
                if (cur > 0) {
                    if (merged_segment_sum <= 0) {
                        positive_count += 1;
                        segment_sum = cur;
                        continue;
                    }

                    positive_count += 1;
                    negative_count -= 1;
                    segment_sum = merged_segment_sum;
                }

                if (cur < 0) {
                    segment_sum = merged_segment_sum;
                }

                continue;
            }

            if (cur > 0) {
                positive_count += 1;
            } else {
                negative_count += 1;
            }

            segment_sum = cur;
        }

        bool success = positive_count > negative_count;
        cout << (success ? "YES" : "NO") << '\n';
    }
}