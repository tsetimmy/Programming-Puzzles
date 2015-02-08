#include <iostream>
#include <utility>
#include <cassert>
using namespace std;

typedef long long ll;
#define dim 8


pair<ll,ll> grid [dim][dim];
ll rowok [dim], colok [dim];
ll best;

bool inbound (ll row, ll col) {
  return !(row >= dim || row < 0 || col >= dim || col < 0);
}

bool diagok (ll row, ll col) {
  ll r, c;

  r = row;
  c = col;
  while (inbound(r, c)) {
    if (grid[r][c].first) {
      return false;
    }
    r--;
    c--;
  }

  r = row;
  c = col;
  while (inbound(r, c)) {
    if (grid[r][c].first) {
      return false;
    }
    r--;
    c++;
  }

  r = row;
  c = col;
  while (inbound(r, c)) {
    if (grid[r][c].first) {
      return false;
    }
    r++;
    c++;
  }

  r = row;
  c = col;
  while (inbound(r, c)) {
    if (grid[r][c].first) {
      return false;
    }
    r++;
    c--;
  }

  return true;
}


void doit (ll curr, ll used) {
  if (curr == dim*dim && used == dim) {
    ll tot = 0;
    ll count = 0;
    for (ll i = 0; i < dim; i++) {
      for (ll j = 0; j < dim; j++) {
        if (grid[i][j].first) {
          tot += grid[i][j].second;
          count++;
        }
      }
    }
    assert(count == dim);
    best = max(best, tot);

    return;
  }
  if (curr >= dim*dim) return;
  ll row = curr/dim;
  ll col = curr%dim;

  if (rowok[row] && colok[col] && diagok(row, col)) {
    rowok[row] = 0;
    colok[col] = 0;
    grid[row][col].first = 1;
    doit(curr+1, used+1);
    grid[row][col].first = 0;
    rowok[row] = 1;
    colok[col] = 1;
  }
  doit(curr+1, used);

}

void getboard () {
  best = -1;
  for (ll i = 0; i < dim; i++) {
    rowok[i] = 1;
    colok[i] = 1;
    for (ll j = 0; j < dim; j++) {
      grid[i][j].first = 0;
      cin >> grid[i][j].second;
    }
  }
}

void print (ll num) {
  ll count = 0;
  ll temp = num;

  while (temp != 0) {
    temp /= 10;
    count++;
  }

  for (ll i = 0; i < 5 - count; i++) {
    cout << " ";
  }
  cout << num << endl;
}

int main () {
  ll k;
  cin >> k;
  for (ll i = 0; i < k; i++) {
    getboard();
    doit(0,0);
    print(best);
  }
  return 0;
}
