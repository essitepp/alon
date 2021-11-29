#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  string s;
  cin >> s;
  int n = s.size();

  set<string> stringSet;

  vector<string> strings;
  strings.push_back(s);
  stringSet.insert(s);

  int k = 0;
  while (k < (int) strings.size()) {
    string str = strings[k];
    for (int i = 0; i < n-1; i++)
    {
      for (int j = 1; j < n; j++)
      {
        if (i == j) continue;
        string newString = str;
        swap(newString[i], newString[j]);
        if (stringSet.count(newString) == 0) {
          stringSet.insert(newString);
          strings.push_back(newString);
        }
      }
      
    }
    k++;    
  }
  cout << strings.size() << "\n";
  sort(strings.begin(), strings.end());
  for (int i = 0; i < (int) strings.size(); i++) {
    cout << strings[i] << "\n";
  }

}