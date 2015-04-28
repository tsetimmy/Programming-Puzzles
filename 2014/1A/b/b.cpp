// Works for both small and large inputs.
#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
using namespace std;

#define dim 1001
#define mx 10000
vector<int> graph [dim];

int m (int a, int b) {
  if (a > b)
    return a;
  else
    return b;
}

int recurse (int p, int c) {
  if (graph[c].size() == 1 || graph[c].size() == 2) {
    return 1;
  }
  vector<int> t;
  for (int i = 0; i < graph[c].size(); i++) {
    if (graph[c][i] != p) {
      t.push_back(recurse(c, graph[c][i]));
    }
  }
  sort(t.begin(), t.end());
  return 1 + t[t.size() - 1] + t[t.size() - 2];
}

void doit (int cas) {
  for (int i = 0; i < dim; i++) {
    graph[i].clear();
  }
  int n, a, b;
  cin >> n;
  for (int i = 0; i < n - 1; i++) {
    cin >> a >> b;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }
  int ans = -1;
  for (int i = 0; i < dim; i++) {
    if (graph[i].size() != 0) {
      if (graph[i].size() == 1) {
        ans = m(ans, 1);
      } else if (graph[i].size() == 2) {
        ans = m(ans, 1 + recurse(i, graph[i][0]) + recurse(i, graph[i][1]));
      } else {
        vector<int> t;
        for (int j = 0; j < graph[i].size(); j++) {
          t.push_back(recurse(i, graph[i][j]));
        }
        sort(t.begin(), t.end());
        ans = m(ans, 1 + t[t.size() - 1] + t[t.size() - 2]);
      }
    }
  }
  cout << "Case #" << cas << ": " << n - ans << endl;
}

int main () {
  int tcases;
  cin >> tcases;
  for (int t = 0; t < tcases; t++) {
    doit(t + 1);
  }
  return 0;
}
