// Works for both small and large inputs.
#include <iostream>
#include <vector>
using namespace std;

int R, C, N;

int dc[4]  = {0, -1, 0, 1};
int dr[4] = {-1, 0, 1, 0};

bool inbounds (int r, int c) {
  return (r >= 0 && r < R && c >= 0 && c < C);
}

int count (vector<vector<int> > &g) {
  int c = 0;
  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      if (g[i][j] == 1) {
        for (int k = 0; k < 4; k++) {
          if (inbounds(i + dr[k], j + dc[k]) && g[i + dr[k]][j + dc[k]] != 0 && g[i + dr[k]][j + dc[k]] != 2) {
            c++;
          }
        }
        g[i][j] = 2;
      }
    }
  }
  return c;
}

void try_place (vector<vector<int> > &g, int r, int c, int& N) {
  if (g[r][c] == 1)
    return;
  g[r][c] = 1;
  N--;
}

void fill_diag (vector<vector<int> > &g, int s, int& N) {
  int i, r, c;
  for (i = s; i >= 0; i -= 2) {
    r = i;
    c = 0;
    while (inbounds(r, c)) {
      if (g[r][c] != 1) {
        g[r][c] = 1;
        N--;
      }
      r++;
      c++;
    }
  }

  if (i == -2) i = 2;
  else i = 1;

  for (int j = i; j < C; j += 2) {
    r = 0;
    c = j;
    while (inbounds(r, c)) {
      if (g[r][c] != 1) {
        g[r][c] = 1;
        N--;
      }
      r++;
      c++;
    }
  }
}

int place (int s) {

  vector<vector<int> > g;
  g = vector<vector<int> > (R);
  for (int i = 0; i < R; i++)
    g[i] = vector<int> (C);

  for (int r = 0; r < R; r++)
    for (int c = 0; c < C; c++)
      g[r][c] = 0;

  fill_diag(g, s, N);

  if (N <= 0) {
    return 0;
  }

  try_place(g, 0, 0, N);
  if (N <= 0) { return count(g); }
  try_place(g, 0, C - 1, N);
  if (N <= 0) { return count(g); }
  try_place(g, R - 1, 0, N);
  if (N <= 0) { return count(g); }
  try_place(g, R - 1, C - 1, N);
  if (N <= 0) { return count(g); }

  for (int i = 0; i < R; i++) {
    try_place(g, i, 0, N);
    if (N <= 0) { return count(g); }
  }
  for (int i = 0; i < R; i++) {
    try_place(g, i, C - 1, N);
    if (N <= 0) { return count(g); }
  }
  for (int i = 0; i < C; i++) {
    try_place(g, 0, i, N);
    if (N <= 0) { return count(g); }
  }
  for (int i = 0; i < C; i++) {
    try_place(g, R - 1, i, N);
    if (N <= 0) { return count(g); }
  }

  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      try_place(g, i, j, N);
      if (N <= 0) { return count(g); }
    }
  }

}

void doit (int cas) {
  cout << "Case #" << cas << ": ";
  cin >> R >> C >> N;
  int tmp = N;
  int a = place(R - 1);
  N = tmp;
  int b = place(R - 2);
  cout << min(a, b) << endl;
}

int main () {
  int tcases;
  cin >> tcases;
  for (int cas = 0; cas < tcases; cas++)
    doit(cas + 1);
  return 0;
  cin >> R >> C >> N;
}
