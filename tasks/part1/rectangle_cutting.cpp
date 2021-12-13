#include <iostream>

using namespace std;

int counts[501][501];

int main() {
  for (int i = 1; i <= 500; i++)
  {
      for (int j = i; j <= 500; j++) {
        if (i == j) continue;

        int count = 100000;

        int x = 1;
        while (x < j) {
          count = min(count, counts[i][x] + counts[i][j-x] + 1);
          x++;
        }
        int y = 1;
        while (y < i) {
          count = min(count, counts[y][j] + counts[i-y][j] + 1);
          y++;
        }

        counts[i][j] = count;
        counts[j][i] = count;

      }
  }

  int a, b;
  cin >> a >> b;
  cout << counts[a][b] << "\n";  
}