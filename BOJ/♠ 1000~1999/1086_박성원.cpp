#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

long long int dp[32768][100] = {};
int plainDp[51];
int mod;
string temp[15];
int storage[15];

int getMod(string &s) {
	int result = 0;

	for (size_t i = 0; i < s.length(); i++) {
		result *= 10;
		result += s[i] - '0';
		result %= mod;
	}
	return result;
}

long long int getGcd(long long int a, long long int b) {
	if (b == 0) return 0;
	while (true) {
		long long c = a % b;
		if (c == 0) return b;
		a = b;
		b = c;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int num;
	cin >> num;

	for (int i = 0; i < num; i++) {
		cin >> temp[i];
	}
	cin >> mod;

	for (int i = 0; i < num; i++) {
		storage[i] = getMod(temp[i]);
	}
	dp[0][0] = 1;

	int plain = 1;
	for (int i = 1; i <= 50; i++) {
		plain *= 10;
		plain %= mod;
		plainDp[i] = plain;
	}

	for (int i = 0; i < (1 << num); i++) {
		for (int j = 0; j < num; j++) {
			if ((i & (1 << j)) != 0) continue;
			for (int k = 0; k < mod; k++) {
				int m = (k * plainDp[temp[j].length()] + storage[j]) % mod;
				dp[i | (1 << j)][m] += dp[i][k];
			}
		}
	}

	int s = (int)pow(2, num) - 1;
	long long int all = 1;
	long long int zero = dp[s][0];
	for (int i = 2; i <= num; i++) {
		all *= i;
	}

	long long int gcd = getGcd(all, zero);
	
	if (gcd == 0) {
		cout << "0/1";
	}
	else {
		cout << zero / gcd << '/' << all / gcd;
	}
}