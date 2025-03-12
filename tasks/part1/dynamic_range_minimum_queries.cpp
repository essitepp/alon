#include <iostream>
#include <vector>
#include <tuple>
#include <limits>

int arr[400000];
int tree[800000];
std::tuple<int, int, int> queries[200000];
int n;

void update(int k, int u) {
    k += n-1;
    tree[k] = u;
    for (k /= 2; k >= 1; k /= 2) {
        tree[k] = std::min(tree[2*k], tree[2*k+1]);
    }
}

int getMin(int a, int b) {
    a += n-1; b += n-1;
    int min = std::numeric_limits<int>::max();
    while (a <= b) {
        if (a%2 == 1) {
            min = std::min(min, tree[a++]);
        }
        if (b%2 == 0) {
            min = std::min(min, tree[b--]);
        }
        a /= 2; b /= 2;
    }
    return min;
}

void printTree() {
    for (int i = 0; i < 2*n; ++i) {
        std::cout << tree[i] << " ";
    }
    std::cout << "\n";
}


int main() {
    int q;
    std::cin >> n >> q;

    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }

    int m = 1;
    while (m < n) m *= 2;

    n = m;

    int x, y, z;
    for (int i = 0; i < q; ++i) {
        std::cin >> x >> y >> z;
        queries[i] = { x, y, z };
    }

    //create segment tree
    // bottom level
    for (int i = 0; i < n; ++i) {
        tree[i+n] = arr[i];
    }
    // higher levels
    for (int k = n-1; k > 0; --k) {
        tree[k] = std::min(tree[2*k], tree[2*k+1]);
    }

    std::vector<int> results;

    //run queries
    for (int i = 0; i < q; ++i) {
        auto [type, a, b] = queries[i];
        if (type == 1) {
            update(a, b);
        } else {
            results.push_back(getMin(a, b));
        }
    }

    for (auto res : results) {
        std::cout << res << "\n";
    }

}