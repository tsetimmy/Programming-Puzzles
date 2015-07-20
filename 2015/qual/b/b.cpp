// Works for both small and large inputs.
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

typedef long long ll;
ll D;
vector<ll> P;

ll get (ll a, ll b) {
  ll ret = 0;
  while (a > b) {
    ret++;
    a -= b;
  }
  return ret;
}

void doit (ll cas) {
  cin >> D;
  P = vector<ll> (D);
  for (ll i = 0; i < D; i++) {
    cin >> P[i];
  }

  sort(P.begin(), P.end());
  ll best = P[P.size() - 1];

  for (ll mlvl = P[P.size() - 1]; mlvl >= 1; mlvl--) {
    ll ans = 0;
    for (ll i = 0; i < P.size(); i++) {
      if (P[i] > mlvl) {
        ans += get(P[i], mlvl);
      }
    }
    ans += mlvl;
    best = min(best, ans);
  }
  cout << "Case #" << cas << ": " << best << endl;
}

int main () {
  ll tcases;
  cin >> tcases;
  for (ll cas = 1; cas <= tcases; cas++) {
    doit(cas);
  }
  return 0;
}
