#include <iostream>
using namespace std;

typedef long long ll;
#define dim 1000

// Max is 993
ll k, n, grid[dim][dim];
bool done;

void clear () {
  for (ll i = 0; i < dim; i++) {
    for (ll j = 0; j < dim; j++) {
      grid[i][j] = 0;
    }
  }
}

void print () {
  ll count;
  for (ll i = 0; i < n; i++) {
    count = 0;
    for (ll j = 0; j < n; j++) {
      if (grid[i][j]) {
        cout << j + 1;
        count++;
        if (count != n) cout << " ";
      }
    }
    cout << endl;
  }
}

bool ok (ll row, ll col) {
  ll count;

  count = 0;
  for (ll i = 0; i < n; i++) {
    if (grid[row][i]) {
      count++;
    }
  }
  if (count > k) {
    return false;
  }

  count = 0;
  for (ll i = 0; i < n; i++) {
    if (grid[i][col]) {
      count++;
    }
  }
  if (count > k) {
    return false;
  }

  if (grid[row][col]) {
    for (ll i = row - 1; i >= 0; i--) {
      if (grid[i][col]) {
        for (ll j = col - 1; j >= 0; j--) {
          if (grid[i][j]) {
            for (ll l = i + 1; l < n; l++) {
              if (grid[l][j] && l == row) {
                return false;
              }
            }
          }
        }
      }
    }
  }

  return true;

}

void recurse (ll c, ll planted) {
  ll row, col;
  row = c/n;
  col = c%n;
  bool good = ok(row, col);

  if (!good) return;

  if (c >= n*n && planted != n*k) return;
  if (c >= n*n && !good) return;

  if (c == n*n && planted == n*k && good) {
    print();
    done = true;
    return;
  }

  grid[row][col] = 1;
  if (ok(row, col)) {
    recurse(c + 1, planted + 1);
  }
  if (done) return;
  grid[row][col] = 0;
  recurse(c + 1, planted);
  if (done) return;

}


void doit () {
  clear();
  done = false;
  recurse(0,0);
}


int main () {
  ll cc = 0;

  while (cin >> k) {
    n = k*k - k + 1;
    if (cc != 0) cout << endl;
    doit();
    cc++;
  }

  return 0;
}
