#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>

using namespace std;

int inRoom[300000];
vector<pair<pair<long, long>, int>> customers;
set<int> freeRooms;
//reservation end date, room number
priority_queue<pair<long, int>> reservedRooms;


int main() {
  int n;
  cin >> n;

  for (int i = 0; i < n; i++)
  {
    int arr, dep;
    cin >> arr >> dep;
    customers.push_back({{arr, dep}, i});
  }

  sort(customers.begin(), customers.end());

  int rooms = 0;

  int day = 0;
  int i = 0;
  while (i < n) {
    // free rooms of leaving customers
    while (!reservedRooms.empty() && -reservedRooms.top().first < day) {
      freeRooms.insert(reservedRooms.top().second);
      reservedRooms.pop();
    }

    // reserve rooms for incoming customers
    while (customers[i].first.first == day)
    {
      int room;
      if (!freeRooms.empty()) {
        room = *freeRooms.begin();
        freeRooms.erase(room);
      } else {
        rooms++;
        room = rooms;
      }
      reservedRooms.push({-customers[i].first.second, room});
      inRoom[customers[i].second] = room;
      i++;
      if (i >= n) break;
    }
    
    day = customers[i].first.first;
  }
  
  cout << rooms << "\n";
  for (int i = 0; i < n; i++)
  {
    cout << inRoom[i] << " ";
  }
  cout << "\n"; 
}
