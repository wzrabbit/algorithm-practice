#include <iostream>
#include <sstream>
#include <vector>
#include <unordered_map>
using namespace std;

struct rData {
    string res, exp;
};

unordered_map<string, long long> price;
vector<rData> recipe;

vector<string> split(string& str, char wild) {
    istringstream i(str);
    string buffer;
    vector<string> result;

    while (getline(i, buffer, wild)) {
        result.push_back(buffer); 
    }

    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        string u;
        long long v;
        cin >> u >> v;

        price[u] = v;
    }

    for (int i = 0; i < m; i++) {
        string u;
        cin >> u;

        vector<string> splited = split(u, '=');
        recipe.push_back({ splited[0], splited[1] });
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            string res = recipe[j].res;
            string exp = recipe[j].exp;
            vector<string> splited = split(exp, '+');
            bool invaild = false;
            long long total = 0;

            for (size_t k = 0; k < splited.size(); k++) {
                long long amount = stoi(splited[k].substr(0, 1));
                string material = splited[k].substr(1);

                if (price.find(material) == price.end()) {
                    invaild = true;
                    break;
                }
                
                total += price[material] * amount;
                if (total > 1000000000) total = 1000000001;
            }

            if (!invaild) {
                if (price.find(res) == price.end()) {
                    price[res] = total;
                }
                else {
                    if (total < price[res]) price[res] = total;
                }
            }
        }
    }

    if (price.find("LOVE") == price.end()) cout << -1;
    else cout << price["LOVE"];
}