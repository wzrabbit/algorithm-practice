#include <iostream>
#include <algorithm>
#include <string>
#include <set>
#include <queue>
using namespace std;

bool visited[50001] = {};
set<string> element = {
	"h", "he", "li", "be", "b", "c", "n", "o", "f", "ne", "na", "mg",
	"al", "si", "p", "s", "cl", "ar", "k", "ca", "sc", "ti", "v", "cr",
	"mn", "fe", "co", "ni", "cu", "zn", "ga", "ge", "as", "se", "br",
	"kr", "rb", "sr", "y", "zr", "nb", "mo", "tc", "ru", "rh", "pd",
	"ag", "cd", "in", "sn", "sb", "te", "i", "xe", "cs", "ba", "hf",
	"ta", "w", "re", "os", "ir", "pt", "au", "hg", "tl", "pb", "bi",
	"po", "at", "rn", "fr", "ra", "rf", "db", "sg", "bh", "hs", "mt",
	"ds", "rg", "cn", "fl", "lv", "la", "ce", "pr", "nd", "pm", "sm",
	"eu", "gd", "tb", "dy", "ho", "er", "tm", "yb", "lu", "ac", "th",
	"pa", "u", "np", "pu", "am", "cm", "bk", "cf", "es", "fm", "md",
	"no", "lr"
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int tc;
	cin >> tc;
	
	string word;
	for (int i = 0; i < tc; i++) {
		cin >> word;
		word = "0" + word;
		size_t len = word.size();
		bool success = false;
		queue<int> que;

		fill(visited, visited + len, 0);
		que.push(0);

		while (que.size()) {
			int c = que.front();
			visited[c] = true;
			que.pop();

			if (c == len - 1) {
				success = true;
				break;
			}
			
			if (c < len - 1 && visited[c + 1] == false) {
				string v(1, word.at(c + 1));
				if (element.find(v) != element.end()) {
					visited[c + 1] = true;
					que.push(c + 1);
				}
			}

			if (c < len - 2) {
				string v(word.substr(c + 1, 2));
				if (element.find(v) != element.end()) {
					visited[c + 2] = true;
					que.push(c + 2);
				}
			}
		}

		if (success) cout << "YES\n";
		else cout << "NO\n";
	}
}