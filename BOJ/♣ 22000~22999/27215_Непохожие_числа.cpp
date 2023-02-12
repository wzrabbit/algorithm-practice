#include <iostream>
#include <set>
#include <vector>
using namespace std;

vector<int> answer;

void check_number(int X, int num) {
    if (X == num) {
        return;
    }
    
    int numbers[2] = {X, num};
    int factor_count = 0;
    set<int> factors;

    for (int i = 0; i < 2; i++) {
        for (int j = 1; j * j <= numbers[i]; j++) {
            if (numbers[i] % j == 0) {
                if (numbers[i] / j == j) {
                    factor_count += 1;
                    factors.insert(j);
                } else {
                    factor_count += 2;
                    factors.insert(numbers[i] / j);
                    factors.insert(j);
                }
            }
        }
    }

    if (factor_count - factors.size() <= 2) {
        answer.push_back(num);
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int X, L, R;
    cin >> X >> L >> R;

    for (int i = L; i <= R; i++) {
        check_number(X, i);
    }
    
    cout << answer.size() << '\n';
    for (size_t i = 0; i < answer.size(); i++) {
        cout << answer[i] << ' ';
    }
    cout << '\n';
}