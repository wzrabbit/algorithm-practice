#include <algorithm>
#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

struct IndexChar {
    char c;
    int i;
};

int N;
string target;
vector<int> pi;

void make_pi_array() {
    pi.resize(target.size());
    fill(pi.begin(), pi.end(), 0);
    int l = 0;

    for (int r = 1; r < int(target.size()); r++) {
        while (l > 0 && target[r] != target[l]) {
            l = pi[l - 1];
        }

        if (target[l] == target[r]) {
            l += 1;
            pi[r] = l;
        }
    }
}

void output_match_result(string &line) {
    int index = 0;
    stack<IndexChar> st;

    for (int i = 0; i < int(line.size()); i++) {
        while (index > 0 && line[i] != target[index]) {
            index = pi[index - 1];
        }

        if (line[i] != target[index]) {
            st.push({line[i], index});
            continue;
        }

        if (index != int(target.size()) - 1) {
            index += 1;
            st.push({line[i], index});
            continue;
        }

        for (int j = 0; j < int(target.size()) - 1; j++) {
            st.pop();
        }

        index = st.empty() ? 0 : st.top().i;
    }

    string result = "";

    while (!st.empty()) {
        result += st.top().c;
        st.pop();
    }

    reverse(result.begin(), result.end());

    cout << result << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    while (cin >> N >> target) {
        make_pi_array();

        cin.get();

        while (N--) {
            string line;
            getline(cin, line);
            output_match_result(line);
        }
    }
}
