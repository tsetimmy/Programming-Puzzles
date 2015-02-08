#include <iostream>
#include <cassert>
using namespace std;


typedef long long ll;
#define dim 40

ll visit[dim];
ll graph[dim][dim];
ll path[dim][dim];
ll sz;
bool getout;
ll largest;

void clear () {
  for (ll i = 0; i < dim; i++) {
    visit[i] = 0;
    for (ll j = 0; j < dim; j++) {
      graph[i][j] = 0;
      path[i][j] = 0;
    }
  }
}

void solve (ll start, ll finish, ll curr){
  if (curr == finish && start != finish) {
    path[start][finish]++;
  }

  for (ll i = 0; i < largest; i++) {
    if (graph[curr][i] && visit[i]) {
      getout = true;
      path[start][finish] = -1;
      return;
    } else if (graph[curr][i] && !visit[i]) {
      visit[i] = 1;
      solve(start, finish, i);
      visit[i] = 0;
      if (getout) return;
    }
  }
}

void check () {
  for (ll i = 0; i < dim; i++) {
    assert(visit[i] == 0);
  }
}

void doit (ll cas) {
  for (ll i = 0; i < largest; i++) {
    for (ll j = 0; j < largest; j++) {
      //if (i != j) {
        getout = false;
        check();
        visit[i] = 1;
        solve(i, j, i);
        visit[i] = 0;
      //}
    }
  }
  cout << "matrix for city " << cas << endl;
  for (ll i = 0; i < largest; i++) {
    for (ll j = 0; j < largest; j++) {
      cout << path[i][j];
      if (j != largest - 1) cout << " ";
    }
    cout << endl;
  }
}



int main () {
  ll from, to;
  ll cas = 0;
  while (cin >> sz) {
    clear();
    largest = -1;
    for (ll i = 0; i < sz; i++) {
      cin >> from >> to;
      largest = max(largest, from);
      largest = max(largest, to);
      graph[from][to] = 1;
    }
    largest++;
    doit(cas);
    cas++;
  }
  return 0;
}
