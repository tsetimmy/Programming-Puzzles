#include <iostream>
#include <cassert>
using namespace std;

int a[4][4];
int b[4][4];

void solve (int t) {
  cout << "Case #" << t << ": ";
  int r1, r2;
  cin >> r1;
  r1--;
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      cin >> a[i][j];
    }
  }
  cin >> r2;
  r2--;
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      cin >> b[i][j];
    }
  }

  int count = 0;
  int idx = -1;
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      if (a[r1][i] == b[r2][j]) {
        idx = i;
        count++;
      }
    }
  }
  if (count == 1) cout << a[r1][idx];
  else if (count > 1) cout << "Bad magician!";
  else if (count == 0) cout << "Volunteer cheated!";
  else assert(0 == 1);
  cout << endl;
}

int main () {
  int tcases;
  cin >> tcases;
  for (int t = 1; t <= tcases; t++) {
    solve(t);
  }
  return 0;
}
