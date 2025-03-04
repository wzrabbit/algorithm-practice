#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
using namespace std;

struct Pokemon {
    int info[7];
    string name, type1, type2;
};

struct Filter {
    int min, max;
};

map<string, int> info_map = {
    {"idx", 0},         {"hp", 1},          {"atk", 2},  {"def", 3},
    {"special_atk", 4}, {"special_def", 5}, {"speed", 6}};

struct CursorHistory {
    int id;
    string direction;
};

struct ResizeHistory {
    int id;
    string direction;
    int value;
};

string POKEMON_TYPES[18] = {
    "bug",    "dark",   "dragon",  "electric", "fairy",  "fighting",
    "fire",   "flying", "ghost",   "grass",    "ground", "ice",
    "normal", "poison", "psychic", "rock",     "steel",  "water"};

Pokemon pokemons[200001];
int N, Q;

int R = 5, C = 5;
int cursor_position = 1;

vector<int> sort_conditions;
bool is_condition_ascending[7];

Filter range_filter[7];
string prefix_filter = "";
set<string> type_filter;

queue<CursorHistory> cursor_history;
queue<ResizeHistory> resize_history;

void init_filters() {
    for (int i = 0; i < 7; i++) {
        range_filter[i] = {1, 200'000};
    }

    for (string pokemon_type : POKEMON_TYPES) {
        type_filter.insert(pokemon_type);
    }

    sort_conditions.push_back(0);
    is_condition_ascending[0] = true;
}

void pre_sort_pokemons(string type, bool ascending) {
    cursor_position = 1;

    while (!cursor_history.empty()) {
        cursor_history.pop();
    }

    int type_no = info_map[type];

    auto it = find(sort_conditions.begin(), sort_conditions.end(), type_no);

    if (it != sort_conditions.end()) {
        sort_conditions.erase(it);
    }

    sort_conditions.push_back(type_no);
    is_condition_ascending[type_no] = ascending;
}

void pre_filter_pokemons(string filter_name, string arg1, int arg2 = 0) {
    cursor_position = 1;

    while (!cursor_history.empty()) {
        cursor_history.pop();
    }

    if (filter_name == "name") {
        if (arg1 == "BLANK") {
            prefix_filter = "";
            return;
        }

        prefix_filter = arg1;
        return;
    }

    if (filter_name == "type") {
        if (type_filter.find(arg1) == type_filter.end()) {
            type_filter.insert(arg1);
            return;
        }

        type_filter.erase(arg1);
        return;
    }

    if (arg1 == "min") {
        range_filter[info_map[filter_name]].min = arg2;
        return;
    }

    range_filter[info_map[filter_name]].max = arg2;
}

void pre_resize_grid(int query_id, string type, int value) {
    resize_history.push({query_id, type, value});
}

void pre_move_cursor(int query_id, string direction) {
    cursor_history.push({query_id, direction});
}

bool check_condition_satisfy(int index) {
    Pokemon& pokemon = pokemons[index];

    for (int i = 0; i < 7; i++) {
        if (pokemon.info[i] < range_filter[i].min ||
            pokemon.info[i] > range_filter[i].max) {
            return false;
        }
    }

    if (prefix_filter.size() > pokemon.name.size()) {
        return false;
    }

    for (size_t i = 0; i < prefix_filter.size(); i++) {
        if (prefix_filter[i] != pokemon.name[i]) {
            return false;
        }
    }

    return type_filter.find(pokemon.type1) != type_filter.end() ||
           type_filter.find(pokemon.type2) != type_filter.end();
}

void sort_pokemons() {
    sort(pokemons + 1, pokemons + N + 1,
         [&](const Pokemon& a, const Pokemon& b) {
             for (int i = int(sort_conditions.size()) - 1; i >= 0; i--) {
                 int type_no = sort_conditions[i];
                 bool ascending = is_condition_ascending[type_no];

                 if (a.info[type_no] == b.info[type_no]) {
                     continue;
                 }

                 if (ascending) {
                     return a.info[type_no] < b.info[type_no];
                 }

                 return a.info[type_no] > b.info[type_no];
             }

             return false;
         });
}

void update_cursor(CursorHistory cursor_history, int pokemon_count) {
    if (cursor_history.direction == "u") {
        cursor_position -= C;
        cursor_position = max(1, cursor_position);
        return;
    }

    if (cursor_history.direction == "d") {
        cursor_position += C;
        cursor_position = min(pokemon_count, cursor_position);
        return;
    }

    if (cursor_history.direction == "l") {
        if (cursor_position > 1) {
            cursor_position -= 1;
        }
        return;
    }

    if (cursor_position < pokemon_count) {
        cursor_position += 1;
    }
}

void update_board_size(ResizeHistory resize_history) {
    if (resize_history.direction == "W") {
        C = resize_history.value;
        return;
    }

    R = resize_history.value;
}

void output_answer() {
    sort_pokemons();

    vector<int> filtered_pokemons;

    for (int i = 1; i <= N; i++) {
        if (check_condition_satisfy(i)) {
            filtered_pokemons.push_back(pokemons[i].info[0]);
        }
    }

    int pokemon_count = filtered_pokemons.size();

    while (!cursor_history.empty() || !resize_history.empty()) {
        if (cursor_history.empty()) {
            update_board_size(resize_history.front());
            resize_history.pop();
            continue;
        }

        if (resize_history.empty()) {
            update_cursor(cursor_history.front(), pokemon_count);
            cursor_history.pop();
            continue;
        }

        CursorHistory cursor_history_item = cursor_history.front();
        ResizeHistory resize_history_item = resize_history.front();

        if (cursor_history_item.id < resize_history_item.id) {
            update_cursor(cursor_history_item, pokemon_count);
            cursor_history.pop();
            continue;
        }

        update_board_size(resize_history_item);
        resize_history.pop();
    }

    vector<vector<int>> screen(R + 1, vector<int>(C + 1, 0));

    int start_index = (cursor_position - 1) / C * C;

    for (int i = start_index; i < min(pokemon_count, start_index + R * C);
         i++) {
        int r = (i - start_index) / C + 1;
        int c = (i - start_index) % C + 1;
        screen[r][c] = filtered_pokemons[i];
    }

    for (int r = 1; r <= R; r++) {
        for (int c = 1; c <= C; c++) {
            cout << screen[r][c] << ' ';
        }
        cout << '\n';
    }

    cout << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> pokemons[i].name >> pokemons[i].type1 >> pokemons[i].type2;
        pokemons[i].info[0] = i;

        for (int j = 1; j < 7; j++) {
            cin >> pokemons[i].info[j];
        }
    }

    init_filters();

    cin >> Q;

    for (int q = 1; q <= Q; q++) {
        string command;
        cin >> command;

        if (command == "sort") {
            string type, asc;
            cin >> type >> asc;
            pre_sort_pokemons(type, asc == "asc");
            continue;
        }

        if (command == "filter") {
            string type, arg1;
            int arg2;
            cin >> type >> arg1;

            if (type == "name") {
                pre_filter_pokemons("name", arg1);
                continue;
            }

            if (type == "type") {
                pre_filter_pokemons("type", arg1);
                continue;
            }

            cin >> arg2;
            pre_filter_pokemons(type, arg1, arg2);
            continue;
        }

        if (command == "resize") {
            string direction;
            int value;
            cin >> direction >> value;
            pre_resize_grid(q, direction, value);
            continue;
        }

        if (command == "cursor") {
            string direction;
            cin >> direction;
            pre_move_cursor(q, direction);
            continue;
        }

        output_answer();
    }
}
