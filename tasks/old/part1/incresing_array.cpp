#include <iostream>

using namespace std;

int main() {
  int n;
  cin >> n;
  int a[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  long res = 0;
  for (int i = 1; i < n; i++)
  {
    long diff = a[i] - a[i-1];
    if (diff < 0) {
      a[i] = a[i-1];
      res -= diff;
    }
  }
  cout << res;  
}