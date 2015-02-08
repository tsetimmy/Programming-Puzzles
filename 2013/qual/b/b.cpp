// C++
#include <iostream>
#include <algorithm>
#include <vector>
#include <limits>
#include <queue>
#include <stack>
#include <utility> // pair
// C
#include <stdlib.h> // atoi, qsort
#include <math.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
#define ullmax std::numeric_limits<unsigned long long>::max()
#define llmax std::numeric_limits<long long>::max()
#define intmax std::numeric_limits<int>::max()
string tokenize (string &target, string delimiter);

struct cell {
  int c;
  bool out;
  bool visited;
};

int N,M;
cell map[102][102];
string ans;
int dx[4] = {0, 0, -1, 1}, dy[4] = {-1, 1, 0, 0};

void clear () {
  for (int i = 0; i < 102; i++)
    for (int j = 0; j < 102; j++) {
      map[i][j].c = 0;
      map[i][j].out = false;
    }
}

void clear2 () {
  for (int i = 0; i < 102; i++)
    for (int j = 0; j < 102; j++)
      map[i][j].visited = false;

}

void dfs (int x, int y, int val) {
  if (x < 0 || y < 0 || x > N+1 || y > M+1) return;
  cell* e = &map[x][y];

  if (e->visited) return;
  if (e->c > val) return;
  if (e->out) return;
  if (e->c == val) e->out = true;

  e->visited = true;
  int nx, ny;
  for (int i = 0; i < 4; i++) {
    nx = x + dx[i];
    ny = y + dy[i];
    dfs(nx, ny, val);
  }

}

void solve (int t) {
  clear();
  cin >> N >> M;
  for (int n = 1; n <= N; n++)
    for (int m = 1; m <= M; m++)
      cin >> map[n][m].c;

  for (int i = 100; i >= 1; i--) {
    clear2();
    dfs(0,0,i);
  }

  
  for (int n = 1; n <= N; n++)
    for (int m = 1; m <= M; m++) {
      if (!map[n][m].out) {
        ans = "NO";
        goto done;
      }
    }
  ans = "YES";

  done:
  cout << "Case #" << t << ": " << ans << endl;

}

int main () {
  int T; cin >> T;
  for (int t = 1; t <= T; t++)
    solve(t);
  return 0;
}







































































































string tokenize (string &target, string delimiter) {
  if (target == "")
    return target;

    string ret = "";
    size_t found = target.find(delimiter);
    if (found == std::string::npos && target != "") {
      ret = target;
      target = "";
    } else {
      ret = target.substr(0, found);
      target = target.substr(found+1,target.length());
    }
    return ret;
}
