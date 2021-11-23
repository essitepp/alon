#include <iostream>

using namespace std;

int main() {
  int n;
  cin >> n;
  if (n%4 == 1 || n%4 == 2) {
    cout << "NO";
    return 0;
  }
  cout << "YES";
  
  int set1[1000000];
  int set2[1000000];
  int count1 = 0;
  int count2 = 0;

  int n0 = n;

  while (n > 0) {
    if (n%4 == n0%4 || n%4 == (n0+1)%4) {
      set1[count1] = n;
      count1++;
    } else {
      set2[count2] = n;
      count2++;
    }
    n--;
  }
  cout << "\n" << count1 << "\n";
  for (int i = 0; i < count1; i++) {
    cout << set1[i] << " ";
  }
  cout << "\n" << count2 << "\n";
  for (int i = 0; i < count2; i++) {
    cout << set2[i] << " ";
  }

}