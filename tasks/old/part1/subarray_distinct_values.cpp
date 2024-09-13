#include <iostream>
#include <set>
#include <map>

using namespace std;

int arr[300000];
map<long, long> values;

int main() {
  int n, k;
  cin >> n >> k;

  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }

  int i = 0;
  int j = 0;
  long count = 0;
  int distinct = 0;

  values[arr[0]]++;
  distinct++;

  while (i < n) {
    while (j < n-1 && (distinct < k || values[arr[j+1]] > 0)) {
      j++;
      values[arr[j]]++;
      if (values[arr[j]] == 1) distinct++;
    }
    count += j - i + 1;
    values[arr[i]]--;
    if (values[arr[i]] == 0) distinct--;
    i++;
  }

  cout << count << "\n";
}
