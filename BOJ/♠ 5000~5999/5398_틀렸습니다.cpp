#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Word {
    int r, c;
    string word;
};

char canvas[2010][2010];
bool visited[500];
int L[1000];
int R[1000];
vector<Word> horizontal_words, vertical_words;
vector<int> graph[1000];
int horizontal_count, vertical_count;

bool is_collide(int h, int v) {
    Word &horizontal_word = horizontal_words[h];
    Word &vertical_word = vertical_words[v];
    bool collide = false;

    for (size_t i = 0; i < horizontal_word.word.size(); i++) {
        int r = horizontal_word.r;
        int c = horizontal_word.c + i;
        char letter = horizontal_word.word[i];

        canvas[r][c] = letter;
    }

    for (size_t i = 0; i < vertical_word.word.size(); i++) {
        int r = vertical_word.r + i;
        int c = vertical_word.c;
        char letter = vertical_word.word[i];

        if (canvas[r][c] != NULL && canvas[r][c] != letter) {
            collide = true;
            break;
        }

        canvas[r][c] = letter;
    }

    for (size_t i = 0; i < horizontal_word.word.size(); i++) {
        int r = horizontal_word.r;
        int c = horizontal_word.c + i;
        char letter = horizontal_word.word[i];

        canvas[r][c] = NULL;
    }

    for (size_t i = 0; i < vertical_word.word.size(); i++) {
        int r = vertical_word.r + i;
        int c = vertical_word.c;
        char letter = vertical_word.word[i];

        canvas[r][c] = NULL;
    }

    return collide;
}

bool dfs(int cur) {
    if (visited[cur]) {
        return false;
    }

    visited[cur] = true;

    for (int adj : graph[cur]) {
        if (R[adj] == -1 || (!visited[R[adj]] && dfs(R[adj]))) {
            L[cur] = adj;
            R[adj] = cur;
            return true;
        }
    }

    return false;
}

int get_matched_count() {
    int matched_count = 0;

    for (int i = 0; i < horizontal_count; i++) {
        fill(visited, visited + horizontal_count, false);

        if (dfs(i)) {
            matched_count += 1;
        }
    }

    return matched_count;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int T;
    cin >> T;

    while (T--) {
        cin >> horizontal_count >> vertical_count;

        fill(L, L + horizontal_count, -1);
        fill(R + 500, R + 500 + vertical_count, -1);
        horizontal_words.resize(horizontal_count);
        vertical_words.resize(vertical_count);

        for (int i = 0; i < horizontal_count; i++) {
            graph[i].clear();

            cin >> horizontal_words[i].c >> horizontal_words[i].r >>
                horizontal_words[i].word;
        }

        for (int i = 0; i < vertical_count; i++) {
            graph[i + 500].clear();

            cin >> vertical_words[i].c >> vertical_words[i].r >>
                vertical_words[i].word;
        }

        for (int i = 0; i < horizontal_count; i++) {
            for (int j = 0; j < vertical_count; j++) {
                if (is_collide(i, j)) {
                    graph[i].push_back(j + 500);
                }
            }
        }

        int answer = horizontal_count + vertical_count - get_matched_count();
        cout << answer << '\n';
    }
}
