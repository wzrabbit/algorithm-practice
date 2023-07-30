#include <algorithm>
#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

struct Answer {
    int a, b;
};

stack<int> st;
vector<Answer> answer;

void append_answer(string &S) {
    for (size_t i = 0; i < S.size(); i++) {
        if (i % 2 == 1 && S[i] != ')') {
            st.push(i + 1);
            continue;
        }

        if (i % 2 == 0 && S[i] != '(') {
            answer.push_back({st.top(), int(i) + 1});
            st.pop();
        }
    }
}

void print_answer() {
    cout << answer.size() << '\n';

    for (size_t i = 0; i < answer.size(); i++) {
        cout << answer[i].a << ' ' << answer[i].b << '\n';
    }

    answer.clear();
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int T;
    cin >> T;

    while (T--) {
        int N;
        string A, B;
        cin >> N >> A >> B;

        append_answer(A);
        append_answer(B);
        print_answer();
    }
}