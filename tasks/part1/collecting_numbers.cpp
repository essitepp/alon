#include <iostream>

using namespace std;

int main() {
  int index[300000];
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int value;
    cin >> value;
    index[value] = i;
  }
  int count = 1;
  for (int i = 2; i <= n; i++)
  {
    if (index[i] < index[i-1]) count++;
  }
  cout << count;
}