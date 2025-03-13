#include <iostream>
#include <limits>

int arr[200000];
int tree[800000];
int m;

void printTree() {
    for (int i = 0; i < 2*m; ++i) {
        std::cout << i%10 << " ";
    }
    std::cout << "\n";
    for (int i = 0; i < 2*m; ++i) {
        std::cout << tree[i] << " ";
    }
    std::cout << "\n\n";
}

void update(int k, int u) {
    tree[k] = u;
    for (k /= 2; k >= 1; k /= 2) {
        tree[k] = std::min(tree[2*k], tree[2*k+1]);
    }
}

int main() {
    int n;
    std::cin >> n;

    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }

    m = 1;
    while (m < n) m *= 2;

    //i'th leaf of the tree has the smallest value that is the last element of an 
    // increasing subsequence of length i
    //upper level nodes have minimum value of their children

    //start with no subsequences formed -> all values are infinite
    int inf = std::numeric_limits<int>::max();
    for (int i = 1; i < 2*m; ++i) {
        tree[i] = inf;
    }

    for (int i = 0; i < n; ++i) {
        int val = arr[i];
        if (tree[1] > val) {
            //no preceding smaller values
            // -> using only this value is best way to make subseq of length 1
            update(m, val);
        } else {
            int k = 1;
            while (k < m) {//k is internal node
                if (tree[2*k+1] < val) {
                    k = 2*k+1;
                } else {
                    k = 2*k;
                }
            }
            //now k is length of longest subseq that ends with element smaller than 
            // or equal to val
            // -> if this last element is smaller, can extend the subsequence
            if (tree[k] < val) {
                update(k+1, val);
            }   
        }
    }

    //then find longest subsequence that can be made
    // -> rightmost leaf with value smaller than inf
    int k = 1;
    while (k < m) {
        if (tree[2*k+1] < inf) {
            k = 2*k+1;
        } else {
            k = 2*k;
        }
    }

    std::cout << k-m+1 << "\n";
}