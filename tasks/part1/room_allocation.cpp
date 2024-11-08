#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>

int main() {
    size_t n, a, b;
    std::cin >> n;
    std::vector<std::tuple<size_t, size_t, size_t>> guests(n);
    for (size_t i = 0; i < n; ++i) {
        std::cin >> a >> b;
        guests[i] = {a, b, i};
    }
    std::sort(guests.begin(), guests.end());

    // day available, room number
    std::priority_queue<std::pair<size_t, size_t>> rooms; 
    std::vector<size_t> room_allocation(n);
    
    size_t room_count = 0;

    for (size_t i = 0; i < n; ++i) {
        auto [arr, dep, num] = guests[i];
        if (!rooms.empty() && -rooms.top().first <= arr) {
            size_t room_num = rooms.top().second;
            rooms.pop();
            rooms.push({-(dep+1), room_num});
            room_allocation[num] = room_num;
        } else {
            ++room_count;
            rooms.push({-(dep+1), room_count});
            room_allocation[num] = room_count;
        }
    }

    std::cout << room_count << "\n";
    for (size_t i = 0; i < n; ++i) {
        std::cout << room_allocation[i] << " ";
    }
    std::cout << "\n";
}
