#include <iostream>
using namespace std;

#define dim 1000
int graph[dim+1][dim+1];
int map[dim+1];
int N, M;

void clear () {
  for (int i = 0; i < dim+1; i++) {
    for (int j = 0; j < dim+1; j++) {
      graph[i][j] = 0;
    }
  }
}
void clear2 () {
  for (int i = 0; i < dim+1; i++) {
    map[i] = 0;
  }
}

void doit (int start, bool &yes) {
  if (map[start] == 1) {
    cout << "Yes" << endl;
    yes = true;
    return;
  }

  map[start] = 1;
  for (int i = 1; i <= N; i++) {
    if (graph[start][i] == 1) {
      doit(i,yes);
      if (yes) return;
    }
  }
}

void solve (int tcase) {
  clear();
  cin >> N;
  int k;
  for (int n = 1; n <= N; n++) {
    cin >> M;
    for (int m = 1; m <= M; m++) {
      cin >> k;
      graph[n][k] = 1;
    }
  }

  cout << "Case #" << tcase << ": ";
  bool yes;
  for (int i = 1; i <= N; i++) {
    yes = false;
    clear2();
    doit(i,yes);
    if (yes) return;
  }
  cout << "No" << endl;

}

int main () {
  int T; cin >> T;
  for (int t = 1; t <= T; t++) {
    solve(t);
  }
  return 0;
}
