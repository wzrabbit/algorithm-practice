#include <algorithm>
#include <iostream>
#define MAX_SUM 3999
typedef long long ll;
using namespace std;

int N;
bool success = false;

void print_if_possible(ll sum) {
    for (ll b = 1; b <= sum / 2; b++) {
        ll start = 1;
        ll end = (sum - b * 2) / 2;
        ll mid;
        
        while (start <= end) {
            mid = (start + end) / 2;
            ll c = mid;
            ll a = sum - b * 2 - c;
            ll current = a * a * a + c * c * c;
            ll expected = b * b * b * N;

            if (current > expected) {
                start = mid + 1;
            } else if (current < expected) {
                end = mid - 1;
            } else {
                success = true;
                cout << '(' << a << '/' << b << ")^3 + (" << c << '/' << b << ")^3 = " << N << '\n';
                
                return;
            }
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    while (true) {
        cin >> N;

        if (N == 0) {
            break;
        }
        
        success = false;

        for (int i = 1; i <= MAX_SUM; i++) {
            if (success) {
                break;
            }

            print_if_possible(i);
        }
        
        if (!success) {
            cout << "No value.\n";
        }
    }
}