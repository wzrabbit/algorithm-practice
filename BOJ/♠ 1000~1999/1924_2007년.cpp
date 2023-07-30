#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int days_sum[13] = {0, 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};
string day_name[7] = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};

int main() {
    int month, day;
    cin >> month >> day;

    int gap = days_sum[month] + day;
    cout << day_name[gap % 7];
}