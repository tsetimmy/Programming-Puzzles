#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;

typedef long long ll;
#define dim 55
ll vertices[dim];
ll edges[dim][dim];
ll visited[dim];

ll N, M;

bool foo (pair<ll,ll> a, pair<ll,ll> b) {
  return a.first < b.first;
}

string tostring (ll integer) {
  string ret;
  ostringstream convert;
  convert << integer;
  ret = convert.str();
  return ret;
}

void clearvisit () {
  for (ll i = 0; i < dim; i++)
    visited[i] = 0;
}

string recurse (ll idx, string s) {
  visited[idx] = 1;
  s += tostring(vertices[idx]);

  vector<pair<ll,ll> > tmp;
  for (ll i = 0; i < dim; i++) {
    if (edges[idx][i] == 1 && visited[i] == 0) {
      tmp.push_back(make_pair(i, vertices[i]));
    }
  }
  sort(tmp.begin(), tmp.end(), foo);
  string s2 = s;
  for (ll i = 0; i < tmp.size(); i++) {
    if (visited[tmp[i].first] == 0)
      //cout << idx << " --> " << tmp[i].first << endl;
      s2 = recurse(tmp[i].first, s2);
  }
  return s2;
}

void doit (ll cas) {
  for (ll i = 0; i < dim; i++) {
    vertices[i] = 0;
    visited[i] = 0;
  }
  for (ll i = 0; i < dim; i++)
    for (ll j = 0; j < dim; j++)
      edges[i][j] = 0;
  cin >> N >> M;

  ll n, v1, v2;
  for (ll i = 0; i < N; i++) {
    cin >> n;
    vertices[i + 1] = n;
  }
  for (ll i = 0; i < M; i++) {
    cin >> v1 >> v2;
    //cout << v1 << " " << v2 << endl;
    edges[v1][v2] = 1;
    edges[v2][v1] = 1;
  }

  string best = ":";
  string tmp;
  for (ll i = 0; i < dim; i++) {
    if (vertices[i] != 0) {
      clearvisit();
      tmp = recurse(i, "");
      if (tmp < best) {
        best = tmp;
      }
    }
  }
  cout << "Case #" << cas << ": " << best << endl;

}

int main () {
  ll tcases;
  cin >> tcases;
  for (ll cas = 1; cas <= tcases; cas++)
    doit(cas);
  return 0;
}
