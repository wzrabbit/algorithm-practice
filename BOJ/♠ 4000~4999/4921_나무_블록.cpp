#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct BlockInfo {
    int l, r;
};

vector<BlockInfo> block_infos = {{0, 0},  {0, -1}, {-1, -3}, {-1, -1}, {1, 1},
                                 {1, -2}, {-2, 1}, {-2, -2}, {2, 2}};

bool is_valid(string S) {
    int cur = 0;

    for (size_t i = 0; i < S.size(); i++) {
        int block_no = S[i] - '0';

        if (block_infos[block_no].l != cur * -1) {
            return false;
        }

        cur = block_infos[block_no].r;
    }

    return cur == -3;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;

    while (true) {
        string S;
        cin >> S;

        if (S == "0") {
            return 0;
        }

        if (is_valid(S)) {
            cout << t << ". VALID\n";
        } else {
            cout << t << ". NOT\n";
        }

        t += 1;
    }
}
