// Works for both small and large inputs.
#include <iostream>
#include <sstream>
#include <cassert>
#include <queue>
using namespace std;

typedef long long ll;
#define dim 1330
#define sixdig 999999
ll zip[dim];
ll cp[dim];
ll cp2[dim];
ll status[dim];
ll verticies[dim][dim];
string ans;
ll visited_count;
ll M, N;

void recurse_connected (ll idx) {
  for (ll i = 0; i < dim; i++) {
    if (verticies[idx][i] == 1 && cp2[i] != 2) {
      cp2[i] = 2;
      recurse_connected(i);
    }
  }
}

bool connected (ll idx) {
  for (ll i = 0; i < dim; i++) {
    cp2[i] = cp[i];
  }
  recurse_connected(idx);

  for (ll i = 0; i < dim; i++)
    if (zip[i] != sixdig && cp2[i] == 0) {
      return false;
    }
  return true;
}

ll next_idx (ll idx) {
  if (!connected(idx)) {
    return -1;
  }

  ll bidx = -1;
  bool first = true;
  for (ll i = 0; i < dim; i++) {
    if (verticies[idx][i] == 1 && cp[i] == 0) {
      if (first) {
        bidx = i;
        first = false;
      } else if (zip[i] < zip[bidx]) {
        bidx = i;
      }
    }
  }
  return bidx;
}

vector<ll> get_vector (vector<ll> q) {
  vector<ll> ret;
  for (ll i = 0; i < dim; i++)
    cp[i] = status[i];
  for (ll i = 0; i < q.size(); i++)
    ret.push_back(-1);
  for (ll i = q.size() - 1; i >= 0; i--) {
    if (i != q.size() - 1)
      cp[q[i + 1]] = 2;
    ret[i] = next_idx(q[i]);
  }
  return ret;
}

string tostring (ll integer) {
  string ret;
  ostringstream convert;
  convert << integer;
  ret = convert.str();
  return ret;
}

void initialize () {
  visited_count = 0;
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

  vector<ll> q;
  q.push_back(curr_idx);
  status[curr_idx]++;
  ans += tostring(zip[curr_idx]);
  visited_count++;
  while (visited_count < M) {
    curr_idx = q.back();
    vector<ll> b = get_vector(q);

    bool first = true;
    ll bidx;
    ll nidx;
    for (ll i = b.size() - 1; i >= 0; i--) {
      if (b[i] != -1 && first) {
        bidx = i;
        nidx = b[i];
        first = false;
      } else if (b[i] != -1 && !first && zip[b[i]] < zip[nidx]) {
        bidx = i;
        nidx = b[i];
      }
    }

    ll sz = b.size();
    for (ll i = 0; i < sz - 1 - bidx; i++) {
      status[q.back()] = 2;
      q.pop_back();
    }
    q.push_back(nidx);
    status[nidx]++;
    ans += tostring(zip[nidx]);
    visited_count++;
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
