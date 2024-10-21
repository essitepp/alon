#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<std::pair<int, int>> movies;

    int start, end;
    for (int i = 0; i < n; ++i) {
        std::cin >> start >> end;
        movies.push_back({end, start});
    }

    std::sort(movies.begin(), movies.end());

    int count = 0;
    int free = 0;

    for (size_t i = 0; i < movies.size(); ++i) {
        if (movies[i].second >= free) {
            ++count;
            free = movies[i].first;
        }
    }
    std::cout << count << "\n";
}
