#include <iostream>
#include <sstream>
#include <cassert>
#include <queue>
using namespace std;

typedef long long ll;
#define dim 1330
#define sixdig 999999
ll zip[dim];
ll status[dim];
ll verticies[dim][dim];
string ans;

string tostring (ll integer) {
  string ret;
  ostringstream convert;
  convert << integer;
  ret = convert.str();
  return ret;
}

void initialize () {
  ans = "";
  for (ll i = 0; i < dim; i++) {
    zip[i] = sixdig;
    status[i] = 0;
  }
  for (ll i = 0; i < dim; i++)
    for (ll j = 0; j < dim; j++)
      verticies[i][j] = -1;
}

void doit (ll cas) {
  initialize();
  ll M, N;
  cin >> M >> N;
  for (ll i = 0; i < M; i++)
    cin >> zip[i + 1];
  ll t1, t2;
  for (ll i = 0; i < N; i++) {
    cin >> t1 >> t2;
    verticies[t1][t2] = 1;
    verticies[t2][t1] = 1;
  }

  ll curr_idx = 0;
  for (ll i = 0; i < dim; i++)
    if (zip[i] < zip[curr_idx])
      curr_idx = i;

  ll visited_count = 1;
  queue<ll> q;
  q.push(curr_idx);
  status[curr_idx] = 1;
  while (visited_count < M) {
    ll curr = get_best_neighbour(curr_idx);
    ll curr_status = status[curr_idx];
    status[curr_idx] = 2;
    if (q.size() > 1 && connected(q[q.size() - 2]) && zip[get_best_neighbour(q[q.size() - 2])] < zip[curr_idx]) {
    } else {
      status[curr_idx] = curr_status;
    }

  }
  cout << "Case #" << cas << ": " << ans << endl;
}

int main () {
  ll tcases;
  cin >> tcases;
  for (ll cas = 1; cas <= tcases; cas++)
    doit(cas);
  return 0;
}
