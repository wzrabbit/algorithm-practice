#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

multiset<int> prices;

int get_next_lowest_price(int previous_price) {
    auto it = prices.upper_bound(previous_price);
    
    if (it == prices.end()) {
        return -1;
    }
    
    return *it;
}

int get_pages_count() {
    int pages_count = 0;
    int previous_price = -1;
    
    while (true) {
        int searched_price = get_next_lowest_price(previous_price);
        
        if (searched_price == -1) {
            return pages_count;
        }
        
        previous_price = searched_price * 2 - 1;
        pages_count += 1;
    }
}

void erase_single_element(int value) {
    auto target = prices.find(value);
    
    if (target != prices.end()) {
        prices.erase(target);
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int Q;
    cin >> Q;
    
    while (Q--) {
        int command, price;
        cin >> command;
        
        if (command == 1) {
            cin >> price;
            prices.insert(price);
            continue;
        } 
        
        if (command == 2) {
            cin >> price;
            erase_single_element(price);
            continue;
        }
        
        cout << get_pages_count() << '\n';
    }
}
