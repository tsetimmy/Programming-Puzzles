#include <iostream>
#include <cassert>
using namespace std;

typedef long long ll;
#define maxn 2049
#define mcoor 2048

ll grid[maxn][maxn];
ll k, col, row;

ll dr[2] = {-1, 1};
ll dc[2] = {-1, 1};

bool out (ll r, ll c) {
  return r < 0 || r > mcoor || c < 0 || c > mcoor;
}

void print (ll num) {
  if (num == 0) {
    cout << "  " << num << endl;
    return;
  }

  ll t = num;
  ll count = 0;
  while (t != 0) {
    count++;
    t /= 10;
  }

  assert(3 - count > 0);
  for (ll i = 0; i < 3 - count; i++) {
    cout << " ";
  }
  cout << num << endl;
}

void recurse (ll r, ll c, ll kay) {
  if (kay == 0) {
    return;
  }

  ll sidelen = 2*kay + 1;
  ll delta = sidelen/2;

  for (ll i = 0; i < 2; i++) {
    for (ll j = 0; j < 2; j++) {
      assert(!out(delta*dr[i] + r, delta*dc[j] + c));
    }
  }

  for (ll i = r - delta; i < r - delta + sidelen; i++) {
    for (ll j = c - delta; j < c - delta + sidelen; j++) {
      grid[i][j]++;
    }
  }

  for (ll i = 0; i < 2; i++) {
    for (ll j = 0; j < 2; j++) {
      recurse(delta*dr[i] + r, delta*dc[j] + c, kay/2);
    }
  }
}

void doit () {
  for (ll i = 0; i < maxn; i++) {
    for (ll j = 0; j < maxn; j++) {
      grid[i][j] = 0;
    }
  }

  recurse(mcoor/2, mcoor/2, k);
  print(grid[row][col]);
}

int main () {
  while (true) {
    cin >> k >> col >> row;
    if (k == 0 && col == 0 && row == 0) {
      break;
    }
    doit();
  }
  return 0;
}
