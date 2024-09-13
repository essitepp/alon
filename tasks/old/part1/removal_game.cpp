#include <iostream>

using namespace std;

int arr[5001];
pair<long, long> scores[5001][5001];

int main() {
  int n;
  cin >> n;

  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }
  
  for (int i = 0; i < n; i++)
  {
    scores[i][i] = {0, arr[i]};
  }

  for (int i = 0; i < n-1; i++)
  {
    int first = max(arr[i], arr[i+1]);
    int second = min(arr[i], arr[i+1]);

    scores[i][i+1] = {first, second};
  }

  int j = 2;

  while (j < n) {
    int player = j%2 == 0 ? 2 : 1;
    for (int i = 0; i+j < n; i++)
    {
      pair<long, long> chosen;

      if (player == 1) {
        pair<long, long> opt1 = {scores[i][i+j-1].first + arr[i+j], scores[i][i+j-1].second};
        pair<long, long> opt2 = {scores[i+1][i+j].first + arr[i], scores[i+1][i+j].second};

        if (opt1.first > opt2.first) {
          chosen = opt1;
        } else if (opt1.first < opt2.first) {
          chosen = opt2;
        } else {
          if (opt1.second > opt2.second) {
            chosen = opt1;
          } else {
            chosen = opt2;
          }
        }
      } else {
        pair<long, long> opt1 = {scores[i][i+j-1].first, scores[i][i+j-1].second + arr[i+j]};
        pair<long, long> opt2 = {scores[i+1][i+j].first, scores[i+1][i+j].second + arr[i]};
        
        if (opt1.second > opt2.second) {
          chosen = opt1;
        } else if (opt1.second < opt2.second) {
          chosen = opt2;
        } else {
          if (opt1.first > opt2.first) {
            chosen = opt1;
          } else {
            chosen = opt2;
          }
        }
      }

      scores[i][i+j] = chosen;
    }
    j++;
  }
  
  if (n%2 == 0) {
    cout << scores[0][n-1].first << "\n";
  } else {
    cout << scores[0][n-1].second << "\n";
  }
}
