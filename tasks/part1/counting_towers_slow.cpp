#include <iostream>

long long mod = 1e9+7;

int tests[101];
long long tower_pairs[1000001]; //width 1 tower pairs
long long towers1[1000001]; //width 2 towers with width 1 blocks at bottom
long long towers2[1000001]; //width 2 towers with width 2 blocks at bottom

int main() {
    int t;
    std::cin >> t;

    int max_height = 0;
    for (int i = 0; i < t; ++i) {
        std::cin >> tests[i];
        max_height = std::max(max_height, tests[i]);
    }

    // //width 1 tower pairs
    tower_pairs[0] = 1;
    tower_pairs[1] = 1;
    for (int h = 2; h <= max_height; ++h) {
        tower_pairs[h] = (4*tower_pairs[h-1])%mod;
    }

    //width 2 towers
    towers1[0] = 0;
    towers2[0] = 0;
    towers1[1] = 1;
    towers2[1] = 1;
    for (int h = 2; h <= max_height; ++h) { //h = total height
        long long count1 = 0;
        long long count2 = 0;
        // i is height of added bottom block*
        for (int i = 1; i <= h; ++i) {
            // bottom is block of width 2
            // -> bottom of previous tower may have any blocks
            if (h == i) {
                count2 += 1;
            } else {
                count2 += towers1[h-i] + towers2[h-i];
            }
            count2 %= mod;
            
            // bottom is blocks of width 1
            // -> bottom of previous tower must have width 2 blocks
            if (h == i) {
                count1 += tower_pairs[i];
            } else {
                count1 += towers2[h-i]*tower_pairs[i];
            }
            count1 %= mod;
        }
        towers1[h] = count1;
        towers2[h] = count2;
    }
    

    for (int i = 0; i < t; ++i) {
        std::cout << (towers1[tests[i]]+towers2[tests[i]])%mod << "\n";
    }
}