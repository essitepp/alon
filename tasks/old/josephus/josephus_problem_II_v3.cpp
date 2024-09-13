#include <iostream>
#include <vector>
#include <set>

using namespace std;

// int nextChild[300000];
set<int> children;


int main() {
  // cin.tie(0)->sync_with_stdio(0);
  int n, k;
  cin >> n >> k;

  for (int i = 1; i <= n; i++)
  {
    children.insert(i);
  }
  

  // for (int i = 1; i < n; i++)
  // {
  //   nextChild[i] = i+1;
  // }
  // nextChild[n] = 1;
  
  // int remaining = n;
  // vector<int> removedOrder;

  // int index = n;
  // while (remaining > 0) {
  //   int increaseBy = k % remaining;
  //   for (int i = 0; i < increaseBy; i++)
  //   {
  //     index = nextChild[index];
  //   }
  //   removedOrder.push_back(nextChild[index]);
  //   remaining--;
  //   nextChild[index] = nextChild[nextChild[index]];
  // }
  
  // for (int i = 0; i < n; i++)
  // {
  //   cout << removedOrder[i] << " ";
  // }
  // cout << "\n";
}

