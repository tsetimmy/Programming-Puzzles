// Works for both small and large inputs.
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

typedef long long ll;

ll gcd_iter (ll u, ll v) {
  ll t;
  while (v) {
    t = u;
    u = v;
    v = t % v;
  }
  return u < 0 ? -u : u;
}

ll to_int (string s) {
  istringstream buffer(s);
  ll value;
  buffer >> value;
  return value;
}

void doit (ll cas) {
  cout << "Case #" << cas << ": ";
  string s;
  cin >> s;

  string s_n, s_d;

  ll i = 0;
  while (s[i] != '/') {
    s_n.push_back(s[i]);
    i++;
  }
  i++;
  while (i != s.size()) {
    s_d.push_back(s[i]);
    i++;
  }

  ll n, d;
  n = to_int(s_n);
  d = to_int(s_d);

  ll divisor = gcd_iter(n, d);
  n /= divisor;
  d /= divisor;

  if (d % 2 != 0) {
    cout << "impossible" << endl;
    return;
  }

  vector<ll> b;
  bool ok = false;
  for (int i = 0; i < 40; i++) {
    n *= 2;
    if (n >= d) {
      b.push_back(i + 1);
      n -= d;
      if (n == 0) {
        cout << b[0] << endl;
        return;
      }
    }
  }
  cout << "impossible" << endl;
}

int main () {
  ll tcases;
  cin >> tcases;
  for (ll cas = 1; cas <= tcases; cas++) {
    doit(cas);
  }
  return 0;
}
