// Works for both small and large inputs.
#include <iostream>
#include <cmath>
#include <cassert>
using namespace std;

typedef long long ll;

ll X, L;
string s;


ll m[5][5] = { {0, 0, 0, 0, 0},
                {0, 1, 2, 3, 4},
                {0, 2, -1, 4, -3},
                {0, 3, -4, -1, 2},
                {0, 4, 3, -2, -1} };

ll power (ll val, ll p) {
  if (p == 1) {
    return abs(val);
  } else if (p % 2 == 0) {
    ll i = power(val, p / 2);
    return abs(m[i][i]);
  } else {
    ll i = power(val, (p - 1) / 2);
    i = abs(m[i][i]);
    return abs(m[val][i]);
  }
}

bool possible2 () {
  ll val = 1;
  ll sgn = 1;
  for (ll i = 0; i < L; i++) {
    val = sgn * m[val][(ll)(s[i] - 'g')];
    sgn = (val > 0) ? 1 : -1;
    val = abs(val);
  }

  ll sgn2 = sgn;
  if (X % 2 == 0)
    sgn2 = 1;

  ll sgn3 = 1;
  if (val == 2 || val == 3 || val == 4) {
    ll mod = X % 4;
    if (mod == 2 || mod == 3)
      sgn3 = -1;
  }
  //assert(val == 2 || val == 3 || val == 4);
  val = abs(power(val, X));


  sgn = sgn2 * sgn3;
  //cout << val << " " << sgn << endl;
  return (val == 1 && sgn == -1);
}

bool possible () {
  ll val = 1;
  ll sgn = 1;
  for (ll i = 0; i < L * X; i++) {
    ll j = i % s.size();
    val = sgn * m[val][(ll)(s[j] - 'g')];
    sgn = (val > 0) ? 1 : -1;
    val = abs(val);
  }

  //assert(val == 2 || val == 3 || val == 4);
  /*
  val = power(val, X);

  ll sgn2 = sgn;
  if (X % 2 == 0)
    sgn2 = 1;

  ll sgn3 = 1;
  if (val == 2 || val == 3 || val == 4) {
    ll mod = X % 4;
    if (mod == 2 || mod == 3)
      sgn3 = -1;
  }

  sgn = sgn2 * sgn3;
  */
  //cout << val << " " << sgn << endl;
  return (val == 1 && sgn == -1);
}

void doit (ll cas) {
  cout << "Case #" << cas << ": ";
  cin >> L >> X >> s;

  //possible2();
  if (!possible2()) {
    cout << "NO" << endl;
    return;
  }

  ll sgn = 1;
  ll val = 1;
  for (ll i = 0; i < L * X; i++) {
    ll j = i % s.size();
    val = sgn * m[val][(ll)(s[j] - 'g')];
    sgn = (val > 0) ? 1 : -1;
    val = abs(val);

    if (val == 2 && sgn == 1) {
      ll val2 = 1;
      ll sgn2 = 1;
      for (ll i2 = i + 1; i2 < L * X; i2++) {
        ll j2 = i2 % s.size();
        val2 = sgn2 * m[val2][(ll)(s[j2] - 'g')];
        sgn2 = (val2 > 0) ? 1 : -1;
        val2 = abs(val2);
        if (val2 == 3 && sgn2 == 1) {
          cout << "YES" << endl;
          return;
        }
      }
    }
  }
  cout << "NO" << endl;
}

int main () {
  ll tcases;
  cin >> tcases;
  for (ll cas = 1; cas <= tcases; cas++) {
    doit(cas);
  }
  return 0;
}
