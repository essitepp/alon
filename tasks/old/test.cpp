#include <iostream>

using namespace std;

int main() {
  pair<int, int> p = {3, 2};
  cout << p.first << ", " << p.second << "\n";

  p.second = 5;
  cout << p.first << ", " << p.second << "\n";

}