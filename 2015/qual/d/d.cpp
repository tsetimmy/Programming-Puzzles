// Works for both small and large inputs.
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define dim 500
int g[dim][dim];
int b[dim][dim];
int X, R, C;
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, -1, 0, 1};
vector<pair<int, int> > d;
bool richard;

void swap (int &a, int &b) {
  int tmp = a;
  a = b;
  b = tmp;
}

void clear_b () {
  for (int i = 0; i < dim; i++)
    for (int j = 0; j < dim; j++)
      b[i][j] = 0;
}

bool outbounds (int r, int c) {
  return (r < 0 || r >= R || c < 0 || c >= C);
}

int recurse_count (int r, int c) {
  if (outbounds(r, c)) {
    return 0;
  }
  b[r][c] = 1;
  int total = 0;
  for (int i = 0; i < 4; i++) {
    if (!outbounds(r + dr[i], c + dc[i]) && b[r + dr[i]][c + dc[i]] == 0) {
      total += recurse_count(r + dr[i], c + dc[i]);
    }
  }
  return 1 + total;
}

bool multiple_of_X () {
  int c;
  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      if (b[i][j] == 0) {
        c = recurse_count(i, j);
        if (c % X != 0)
          return false;
      }
    }
  }
  return true;
}

bool try_put (int r, int c) {
  b[r][c] = 1;
  for (int i = 0; i < d.size(); i++) {
    r += d[i].first;
    c += d[i].second;
    if (!outbounds(r, c))
      b[r][c] = 1;
    else
      return false;
  }
  return true;
}

void recurse (int r, int c, int count) {
  if (count == X) {
    for (int i = 0; i < R; i++) {
      for (int j = 0; j < C; j++) {
        clear_b();
        if (try_put(i, j) && multiple_of_X()) {
          return;
        }
      }
    }
    swap(R, C);
    for (int i = 0; i < R; i++) {
      for (int j = 0; j < C; j++) {
        clear_b();
        if (try_put(i, j) && multiple_of_X()) {
          return;
        }
      }
    }
    richard = true;
    return;
  }

  for (int i = 0; i < 4; i++) {
    if (g[r + dr[i]][c + dc[i]] == 0) {
      g[r + dr[i]][c + dc[i]] = 1;
      d.push_back(make_pair(dr[i], dc[i]));
      recurse(r + dr[i], c + dc[i], count + 1);
      if (richard) return;
      d.pop_back();
      g[r + dr[i]][c + dc[i]] = 0;
    }
  }
}

void doit (int cas) {
  cout << "Case #" << cas << ": ";
  cin >> X >> R >> C;
  if (X == 1) {
    cout << "GABRIEL" << endl;
    return;
  } else if (R * C % X != 0) {
    cout << "RICHARD" << endl;
    return;
  } else if (X >= 7) {
    cout << "RICHARD" << endl;
    return;
  }

  for (int i = 0; i < dim; i++)
    for (int j = 0; j < dim; j++)
      g[i][j] = 0;

  int s = dim / 2;
  d.clear();
  richard = false;
  g[s][s] = 1;
  recurse(s, s, 1);
  g[s][s] = 0;

  if (richard) cout << "RICHARD" << endl;
  else cout << "GABRIEL" << endl;
}

int main () {
  int tcases;
  cin >> tcases;
  for (int cas = 0; cas < tcases; cas++)
    doit(cas + 1);
  return 0;
}
