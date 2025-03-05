#include <iostream>

std::pair<long,long> scores[5001][5001];
long list[5001];

int main() {
    int n;
    std::cin >> n;

    for (int i = 0; i < n; ++i) {
        std::cin >> list[i];
        scores[i][i] = {list[i], 0}; //scores for lists of length 1
    }

    //l = interval length
    for (int l = 2; l <= n; ++l) {
        for (int i = 0; i+l-1 < n; ++i) {
            int j = i+l-1;
            if (l % 2 == 1) {
                //odd player scores
                long score1 = scores[i][j-1].first + list[j];
                long score2 = list[i] + scores[i+1][j].first;
                if (score1 >= score2) {
                    scores[i][j] = {score1, scores[i][j-1].second};
                } else {
                    scores[i][j] = {score2, scores[i+1][j].second};
                }
            } else {
                //even player scores
                long score1 = scores[i][j-1].second + list[j];
                long score2 = list[i] + scores[i+1][j].second;
                if (score1 >= score2) {
                    scores[i][j] = {scores[i][j-1].first, score1};
                } else {
                    scores[i][j] = {scores[i+1][j].first, score2};
                }
            }
        }
    }
    long result = 0;
    if (n%2 == 1) {
        result = scores[0][n-1].first;
    } else {
        result = scores[0][n-1].second;
    }
    std::cout << result << "\n";
}