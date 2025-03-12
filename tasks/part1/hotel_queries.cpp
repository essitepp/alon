#include <iostream>

int freeRooms[800000];
int requiredRooms[200000];
int results[200000];
int n;


void printTree() {
    for (int i = 0; i < 2*n; ++i) {
        std::cout << i%10 << " ";
    }
    std::cout << "\n";
    for (int i = 0; i < 2*n; ++i) {
        std::cout << freeRooms[i] << " ";
    }
    std::cout << "\n";
}

void update(int k, int u) {
    freeRooms[k] = u;
    for (k /= 2; k >= 1; k /= 2) {
        freeRooms[k] = std::max(freeRooms[2*k], freeRooms[2*k+1]);
    }
}

int findHotel(int rooms) {
    int k = 1; //start from root node;
    if (freeRooms[k] < rooms) return 0;

    while (k < n) {
        if (freeRooms[2*k] >= rooms) {
            k = 2*k;
        } else {
            k = 2*k+1;
        }
    }
    update(k, freeRooms[k]-rooms);
    return k-n+1;
}

int main() {
    int m;
    std::cin >> n >> m;

    int n2 = 1;
    while (n2 < n) n2 *= 2;

    for (int i = 0; i < n; ++i) {
        std::cin >> freeRooms[i+n2];
    }
    n = n2;

    for (int i = 0; i < m; ++i) {
        std::cin >> requiredRooms[i];
    }

    //build rest of tree
    for (int k = n-1; k > 0; --k) {
        freeRooms[k] = std::max(freeRooms[2*k], freeRooms[2*k+1]);
    }

    //run queries
    for (int i = 0; i < m; ++i) {
        results[i] = findHotel(requiredRooms[i]);
    }

    for (int i = 0; i < m; ++i) {
        std::cout << results[i] << " ";
    }
    std::cout << "\n";
}