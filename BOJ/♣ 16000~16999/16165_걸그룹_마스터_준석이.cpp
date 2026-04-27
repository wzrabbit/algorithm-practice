#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

map<string, string> member_to_team;
map<string, vector<string>> team_to_members;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N, M;
    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        string team;
        int member_count;
        cin >> team >> member_count;

        vector<string> members;

        for (int j = 1; j <= member_count; j++) {
            string member;
            cin >> member;
            member_to_team[member] = team;
            members.push_back(member);
        }

        sort(members.begin(), members.end());
        team_to_members[team] = members;
    }

    for (int i = 1; i <= M; i++) {
        string data;
        int type;
        cin >> data >> type;

        if (type == 0) {
            for (const string& member : team_to_members[data]) {
                cout << member << '\n';
            }
        } else {
            cout << member_to_team[data] << '\n';
        }
    }
}
