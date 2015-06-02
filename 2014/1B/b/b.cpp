// Works for both small and large inputs.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define dim 30
typedef long long ll;
ll a[dim], b[dim], k[dim];
ll ans;
ll hash[dim][2][2][2];

ll recurse (ll idx, ll lessA, ll lessB, ll lessK) {
  if (idx == -1) {
    if (lessA == 1 && lessB == 1 && lessK == 1)
      return 1;
    else
      return 0;
  }

  ll &h = hash[idx][lessA][lessB][lessK];
  if (h != -1)
    return h;

  ll count = 0;
  vector<pair<ll,ll> >f, s, t;

  if (lessA == 0) {
    if (a[idx] == 0) {
      f.push_back(make_pair(0,0));
    } else {
      f.push_back(make_pair(0,1));
      f.push_back(make_pair(1,0));
    }
  } else {
    f.push_back(make_pair(0,1));
    f.push_back(make_pair(1,1));
  }

  if (lessB == 0) {
    if (b[idx] == 0) {
      s.push_back(make_pair(0,0));
    } else {
      s.push_back(make_pair(0,1));
      s.push_back(make_pair(1,0));
    }
  } else {
    s.push_back(make_pair(0,1));
    s.push_back(make_pair(1,1));
  }

  if (lessK == 0) {
    if (k[idx] == 0) {
      t.push_back(make_pair(0,0));
    } else {
      t.push_back(make_pair(0,1));
      t.push_back(make_pair(1,0));
    }
  } else {
    t.push_back(make_pair(0,1));
    t.push_back(make_pair(1,1));
  }

  for (ll i = 0; i < f.size(); i++)
    for (ll j = 0; j < s.size(); j++)
      for (ll l = 0; l < t.size(); l++)
        if ((ll)(f[i].first & s[j].first) == t[l].first)
          count += recurse(idx - 1, f[i].second, s[j].second, t[l].second);

  h = count;
  return count;
}

void populate (ll a1, ll* a) {
  ll i = 0;
  while (a1 != 0) {
    a[i] = a1 % 2;
    a1 /= 2;
    i++;
  }
}

void swap (ll &left, ll &right) {
  if (right < left) {
    ll tmp = left;
    left = right;
    right = tmp;
  }
}

void doit (ll cas) {
  for (ll i = 0; i < dim; i++)
    for (ll j = 0; j < 2; j++)
      for (ll l = 0; l < 2; l++)
        for (ll m = 0; m < 2; m++)
          hash[i][j][l][m] = -1;
  ans = 0;
  for (ll i = 0; i < dim; i++) {
    a[i] = 0;
    b[i] = 0;
    k[i] = 0;
  }
  ll a1, b1, k1;
  cin >> a1 >> b1 >> k1;
  swap(a1, b1);

  populate(a1, a);
  populate(b1, b);
  populate(k1, k);

  ans = recurse(dim - 1, 0, 0, 0);
  cout << "Case #" << cas << ": " << ans << endl;
}

int main () {
  ll tcases;
  cin >> tcases;
  for (ll cas = 1; cas <= tcases; cas++)
    doit(cas);
  return 0;
}
