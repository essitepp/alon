#include <iostream>

int tree[800000];
int pos[200001];
int results[200001];
int m;

void printTree() {
    for (int i = 0; i < 2*m; ++i) {
        std::cout << i%10 << " ";
    }
    std::cout << "\n";
    for (int i = 0; i < 2*m; ++i) {
        std::cout << tree[i] << " ";
    }
    std::cout << "\n";
}

void update(int k, int u) {
    tree[k] = u;
    for (k /= 2; k >= 1; k /= 2) {
        if (2*k >= m) {//lowest level of internal nodes
            tree[k] = 0;
            if (tree[2*k] > 0) ++tree[k];
            if (tree[2*k+1] > 0) ++tree[k];
        } else {
            tree[k] = tree[2*k] + tree[2*k+1];
        }
    }
}

int remove(int p) {
    //handle tree with only 1 node
    if (m == 1) {
        return tree[1];
    }

    int k = 1; //start at root node
    while (2*k < m) { //loop until reach lowest level of internal nodes
        if (tree[2*k] >= p) {
            k = 2*k;
        } else {
            p -= tree[2*k];
            k = 2*k+1;
        }
    }
    //pick correct leaf
    if (p == 1 && tree[2*k] > 0) {
        k = 2*k;
    } else {
        k = 2*k+1;
    }

    int res = tree[k];
    update(k, 0);
    return res;
}

int main() {
    int n;
    std::cin >> n;

    m = 1;
    while (m < n) m *= 2;

    for (int i = 0; i < n; ++i) {
        std::cin >> tree[i+m];
    }

    for (int i = 0; i < n; ++i) {
        std::cin >> pos[i];
    }

    //build rest of the tree
    //internal nodes contain number of non-zero values in the range
    for (int k = m-1; k > 0; --k) {
        if (2*k >= m) {//lowest level of internal nodes
            tree[k] = 0;
            if (tree[2*k] > 0) ++tree[k];
            if (tree[2*k+1] > 0) ++tree[k];
        } else {
            tree[k] = tree[2*k] + tree[2*k+1];
        }

    }

    for (int i = 0; i < n; ++i) {
        results[i] = remove(pos[i]);
    }

    for (int i = 0; i < n; ++i) {
        std::cout << results[i] << " ";
    }
    std::cout << "\n";
}