#include <iostream>
#include <cmath>
using namespace std;

typedef long long ll;

ll X, L;
string s;


ll m[5][5] = { {0, 0, 0, 0, 0},
                {0, 1, 2, 3, 4},
                {0, 2, -1, 4, -3},
                {0, 3, -4, -1, 2},
                {0, 4, 3, -2, -1} };

void doit (ll cas) {
  cout << "Case #" << cas << ": ";
  cin >> L >> X >> s;
  ll val = 1;
  ll sgn = 1;
  for (ll i = 0; i < L * X; i++) {
    ll j = i % s.size();
    val = sgn * m[val][(ll)(s[j] - 'g')];
    sgn = (val > 0) ? 1 : -1;
    val = abs(val);
  }
  if (!(val == 1 && sgn == -1)) {
    cout << "NO" << endl;
    return;
  }

  sgn = 1;
  val = 1;
  for (ll i = 0; i < L * X; i++) {
    ll j = i % s.size();
    val = sgn * m[val][(ll)(s[j] - 'g')];
    sgn = (val > 0) ? 1 : -1;
    val = abs(val);

    if (val == 2 && sgn == 1) {
      cout << "found i" << endl;
      ll val2 = 1;
      cout << "execute" << endl;
      ll sgn2 = 1;
      cout << "execute2" << endl;
      ll counter = 0;
      for (ll i2 = i + 1; i2 < L * X; i2++) {
        cout << sgn2 << endl;
        ll j2 = i2 % s.size();
        counter++;
        if (counter == 10) return;
        cout << "---------------------" << endl;
        cout << val2 << endl;
        cout << sgn2 << endl;
        cout << s[j2] << endl;
        val2 = sgn2 * m[val2][(ll)(s[j2] - 'g')];
        cout << val2 << endl;
        ll sgn2 = (val2 > 0) ? 1 : -1;
        cout << sgn2 << endl;
        //val2 = abs(val2);
        val2 = (val2 > 0) ? val2 : -val2;
        cout << sgn2 << endl;
        if (val2 == 3 && sgn2 == 1) {
          cout << "YES" << endl;
          return;
        }
        cout << sgn2 << endl;
        cout << "dude" << endl;
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

