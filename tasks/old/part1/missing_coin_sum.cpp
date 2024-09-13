#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> v;
  int a;
  for (int i = 0; i < n; i++)
  {
    cin >> a;
    v.push_back(a);
  }
  sort(v.begin(), v.end());
  long largest = 0;
  long result;
  for (int i = 0; i < n; i++)
  {
    if (v[i] > largest + 1) {
      result = largest + 1;
      break;
    }
    largest += v[i];
    result = largest + 1;
  }
  cout << result << "\n";  
}