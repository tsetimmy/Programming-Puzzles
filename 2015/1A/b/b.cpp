// Works for both small and large inputs.
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

typedef long long ll;
#define tmax 1000000000000

ll B, N;
vector<ll> M;

ll get_n_at_t (ll t) {
  if (t == -1)
    return 0;
  if (t == 0)
    return M.size();
  ll ret = 0;
  for (ll i = 0; i < M.size(); i++) {
    ret += t / M[i];
  }
  return (ret + M.size());
}

void doit (ll cas) {
  cin >> B >> N;
  M.clear();
  M = vector<ll>(B);
  for (ll i = 0; i < B; i++)
    cin >> M[i];

  ll l, r;
  l = -1;
  r = tmax;

  while (l + 1 != r) {
    ll m = (l + r) / 2;
    ll nl = get_n_at_t(l);
    ll nr = get_n_at_t(r);
    ll nm = get_n_at_t(m);

    if (N > nm) {
      l = m;
    } else if (N <= nm) {
      r = m;
    }
  }

  cout << "Case #" << cas << ": ";
  ll c = 0;
  vector<ll> tmp = vector<ll>(M.size());
  if (l == -1) {
    for (ll i = 0; i < M.size(); i++) {
      c++;
      tmp[i] = M[i];
      if (c == N) {
        cout << i + 1 << endl;
        return;
      }
    }
  } else {
    c = get_n_at_t(l);
    for (ll i = 0; i < tmp.size(); i++) {
      tmp[i] = l % M[i];
      if (tmp[i] == 0) {
        tmp[i] = M[i];
      } else {
        tmp[i] = M[i] - tmp[i];
      }
    }
  }

  while (true) {
    ll m = tmp[0];
    for (ll i = 0; i < tmp.size(); i++) {
      m = min(m, tmp[i]);
    }
    for (ll i = 0; i < tmp.size(); i++) {
      tmp[i] -= m;
      if (tmp[i] == 0) {
        tmp[i] = M[i];
        c++;
        if (c == N) {
          cout << i + 1 << endl;
          return;
        }
      }
    }
  }

}

int main () {
  ll tcases;
  cin >> tcases;
  for (ll cas = 0; cas < tcases; cas++)
    doit(cas + 1);
  return 0;
}
