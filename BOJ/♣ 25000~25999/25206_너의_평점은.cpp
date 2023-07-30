#include <algorithm>
#include <iomanip>
#include <iostream>
#include <map>
#include <string>
using namespace std;

map<string, double> grade_map = {
    {"A+", 4.5},
    {"A0", 4.0},
    {"B+", 3.5},
    {"B0", 3.0},
    {"C+", 2.5},
    {"C0", 2.0},
    {"D+", 1.5},
    {"D0", 1.0},
    {"F", 0.0}};

int main() {
    cin.tie(0)->sync_with_stdio(0);

    double total_credit = 0;
    double total_score = 0;

    for (int i = 1; i <= 20; i++) {
        string _, grade;
        double credit;

        cin >> _ >> credit >> grade;

        if (grade != "P") {
            total_credit += credit;
            total_score += grade_map[grade] * credit;
        }
    }

    cout << fixed << setprecision(5) << total_score / total_credit;
}