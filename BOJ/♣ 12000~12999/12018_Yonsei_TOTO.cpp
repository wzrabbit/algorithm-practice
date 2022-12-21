#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int student_points[101];
vector<int> require_points;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int subject, point;
    cin >> subject >> point;

    for (int s = 1; s <= subject; s++) {
        int N, G;
        cin >> N >> G;

        fill(student_points + 1, student_points + 101, 1);

        for (int i = 1; i <= N; i++) {
            cin >> student_points[i];
        }

        sort(student_points + 1, student_points + N + 1, greater<int>());
        require_points.push_back(student_points[G]);
    }

    sort(require_points.begin(), require_points.end());

    int max_subject_count = 0;
    for (size_t i = 0; i < require_points.size(); i++) {
        if (point < require_points[i]) break;
        point -= require_points[i];
        max_subject_count += 1;
    }

    cout << max_subject_count;
}