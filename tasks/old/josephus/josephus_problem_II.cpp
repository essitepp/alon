#include <iostream>
#include <vector>

using namespace std;

int removed[300000];
int i = 0;
int n, k;
int remaining;
// void increase() {
//   i++;
//   if (i > n) i = 1;
// }

void increase() {
  int increaseBy = k % remaining;
  //...
}

int main() {
  cin >> n >> k;
  remaining = n;
  vector<int> removedOrder;
  while (remaining > 0) {
    // for (int j = 0; j <= k; j++)
    // {
    //   increase();
    //   while (removed[i]) increase();
    // }
    increase();
    removedOrder.push_back(i);
    remaining--;
    removed[i] = 1;
  }
  for (int i = 0; i < n; i++)
  {
    cout << removedOrder[i] << " ";
  }
  cout << "\n";
}

