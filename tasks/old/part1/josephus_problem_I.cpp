#include <iostream>
#include <vector>

using namespace std;

int removed[1000000];
int i = 0;
int n;

void increase() {
  i++;
  if (i > n) i = 1;
}

int main() {
  cin >> n;
  int removedCount = 0;
  vector<int> removedOrder;
  while (removedCount < n) {
    for (int j = 0; j < 2; j++)
    {
      increase();
      while (removed[i]) increase();
    }
    removedOrder.push_back(i);
    removedCount++;
    removed[i] = 1;
  }
  for (int i = 0; i < n; i++)
  {
    cout << removedOrder[i] << " ";
  }
  cout << "\n";
}

