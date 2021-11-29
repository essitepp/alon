#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  vector<pair<int, int>> v;
  int n;
  cin >> n;
  int a,b;
  for (int i = 0; i < n; i++)
  {
    cin >> a >> b;
    v.push_back({b, a});
  }
  sort(v.begin(), v.end());
  int count = 0;
  int end = 0;
  for (int i = 0; i < n; i++)
  {
    if (v[i].second >= end) {
      count++;
      end = v[i].first;
    }
  }
  cout << count << "\n";
}