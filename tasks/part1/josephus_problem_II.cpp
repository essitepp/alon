#include <iostream>
#include <vector>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
typedef tree<int,null_type,std::less<int>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;


int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);  
      
    size_t n, k;
    std::cin >> n >> k;

    indexed_set set;
    for (size_t i = 1; i <= n; ++i) {
        set.insert(i);
    }

    std::vector<int> result;

    size_t i = 0;
    while (!set.empty()) {
        i = (i+k) % set.size();
        auto it = set.find_by_order(i);
        result.push_back(*it);
        set.erase(it);
    }

    for (int val : result) {
        std::cout << val << " ";
    }
    std::cout << "\n";
}
