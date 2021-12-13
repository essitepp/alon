#include <iostream>

using namespace std;

long arr[200000];
long mod = 1e9+7;

int main() {
  int n;
  cin >> n;

  if (n%4 == 1 || n%4 == 2) {
    cout << 0 << "\n";
    return 0;
  }

  int sum = 0;
  for (int i = 0; i <= n; i++)
  {
    sum += i;
  }

  int target = sum / 2;

  arr[0] = 1;
  for (int i = 1; i <= n; i++)
  {
    for (int j = target; j >= 0; j--)
    {
      if (j-i >= 0 && arr[j-i] > 0) {
        arr[j] = (arr[j] + arr[j-i]) % mod;
      }
    }
  }

  long multiplier = 1;
  long power = mod-2;
  long base = 2;
  while (power > 0) {
    if (power%2 == 1) {
      multiplier = multiplier * base % mod;
    }
    base = base * base % mod;
    power /= 2;
  }

  long res = (arr[target] * multiplier)%mod;
  cout << res << "\n";
}