#include <iostream>
#include <set>

using namespace std;

multiset<long> tickets;
int customers[300000];
int paid[300000];

int main() {
  int n, m;
  cin >> n >> m;

  for (int i = 0; i < n; i++)
  {
    long h;
    cin >> h;
    tickets.insert(-h);
  }
  
  for (int i = 0; i < m; i++)
  {
    cin >> customers[i];
  }
  
  for (int i = 0; i < m; i++)
  {
    auto it = tickets.lower_bound(-customers[i]);
    if (it == tickets.end()) {
      paid[i] = -1;
    } else {
      paid[i] = -*it;
      tickets.erase(it);
    }
  }
  
  for (int i = 0; i < m; i++)
  {
    cout << paid[i] << "\n";
  }
}
