#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int cnt = 1;

    while (true) {
        string str;
        stack<char> st;
        cin >> str;
        int level = 0;
        int maxLevel = 0;

        if (str == "()") break;

        for (size_t i = 0; i < str.length(); i++) {
            if (str[i] == '(') level++;
            else if (str[i] == ')') level--;
            if (maxLevel < level) maxLevel = level;
        }
        level = maxLevel + 1;

        for (size_t i = 0; i < str.length(); i++) {
            if (str[i] == '(') {
                st.push('(');
                level--;
            }
            else if (str[i] == ')') {
                char temp = st.top();
                st.pop();
                st.pop();
                level++;
                if (!st.empty() && (st.top() == 'T' || st.top() == 'F')) {
                    if (level % 2 == 1) {
                        if (st.top() != 'T' || temp != 'T') {
                            st.pop();
                            st.push('F');
                        }
                    }
                    else {
                        if (st.top() != 'F' || temp != 'F') {
                            st.pop();
                            st.push('T');
                        }
                    }
                }
                else {
                    st.push(temp);
                }
            }
            else {
                if (!st.empty() && st.top() != '(') {
                    if (level % 2 == 1) {
                        if (st.top() != 'T' || str[i] != 'T') {
                            st.pop();
                            st.push('F');
                        }
                    }
                    else {
                        if (st.top() != 'F' || str[i] != 'F') {
                            st.pop();
                            st.push('T');
                        }
                    }
                }
                else {
                    st.push(str[i]);
                }
            }
        }

        cout << cnt << ". ";
        if (st.top() == 'T') {
            cout << "true\n";
        }
        else {
            cout << "false\n";
        }
        cnt++;
    }
}