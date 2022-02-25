#include <iostream>
#include <algorithm>
#include <queue>
#include <unordered_map>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int tc;
    cin >> tc;

    while (tc--)
    {
        priority_queue<int> max_heap;
        priority_queue<int, vector<int>, greater<int>> min_heap;
        unordered_map<int, int> max_junk;
        unordered_map<int, int> min_junk;
        int queue_size = 0;

        int query;
        cin >> query;
        while (query--)
        {
            char command;
            int value;
            cin >> command >> value;

            if (command == 'I')
            {
                max_heap.push(value);
                min_heap.push(value);
                queue_size++;
            }
            else if (queue_size > 0)
            {
                queue_size--;

                if (value == 1)
                {
                    int max_popped;
                    while (true)
                    {
                        max_popped = max_heap.top();
                        max_heap.pop();
                        if (max_junk.find(max_popped) == max_junk.end() || max_junk[max_popped] == 0)
                            break;
                        max_junk[max_popped]--;
                    }
                    if (min_junk.find(max_popped) == min_junk.end())
                        min_junk[max_popped] = 1;
                    else
                        min_junk[max_popped]++;
                }
                else
                {
                    int min_popped;
                    while (true)
                    {
                        min_popped = min_heap.top();
                        min_heap.pop();
                        if (min_junk.find(min_popped) == min_junk.end() || min_junk[min_popped] == 0)
                            break;
                        min_junk[min_popped]--;
                    }
                    if (max_junk.find(min_popped) == max_junk.end())
                        max_junk[min_popped] = 1;
                    else
                        max_junk[min_popped]++;
                }
            }
        }

        int final_max, final_min;
        if (queue_size > 0)
        {
            while (true)
            {
                final_max = max_heap.top();
                if (max_junk.find(final_max) == max_junk.end() || max_junk[final_max] == 0)
                    break;
                max_heap.pop();
                max_junk[final_max]--;
            }

            while (true)
            {
                final_min = min_heap.top();
                if (min_junk.find(final_min) == min_junk.end() || min_junk[final_min] == 0)
                    break;
                min_heap.pop();
                min_junk[final_min]--;
            }
        }

        if (queue_size == 0)
            cout << "EMPTY\n";
        else
            cout << final_max << ' ' << final_min << '\n';
    }
}