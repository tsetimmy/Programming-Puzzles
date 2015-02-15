#include <iostream>
#include <cassert>
using namespace std;

#define dim 4
int a[dim][dim];
int b[dim][dim];

void doit (int cas) {
  int r1, r2;
  cin >> r1;
  r1--;
  for (int i = 0; i < dim; i++) {
    for (int j = 0; j < dim; j++) {
      cin >> a[i][j];
    }
  }
  cin >> r2;
  r2--;
  for (int i = 0; i < dim; i++) {
    for (int j = 0; j < dim; j++) {
      cin >> b[i][j];
    }
  }

  int matches = 0;
  int col = -1;
  for (int i = 0; i < dim; i++) {
    for (int j = 0; j < dim; j++) {
      if (a[r1][i] == b[r2][j]) {
        matches++;
        col = i;
      }
    }
  }

  cout << "Case #" << cas << ": ";
  if (matches == 1) {
    assert(col != -1);
    cout << a[r1][col] << endl;
  } else if (matches > 1) {
    cout << "Bad magician!" << endl;
  } else if (matches == 0) {
    cout << "Volunteer cheated!" << endl;
  } else {
    assert(1 == 0);
  }

}

int main () {
  int cases;
  cin >> cases;
  for (int i = 0; i < cases; i++) {
    doit(i + 1);
  }
  return 0;
}
