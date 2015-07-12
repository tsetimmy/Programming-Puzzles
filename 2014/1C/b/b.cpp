#include <iostream>
#include <limits>
#include <vector>
#include <algorithm>
#include <cassert>
using namespace std;

typedef long long ll;
#define mod 1000000007
#define hdim 500

ll hash[hdim];
vector<string> v;
vector<pair<string, ll> > vv;

ll maximum (ll a, ll b) {
  if (a > b) {
    return a;
  } else {
    return b;
  }
}

void merge (ll l, ll r) {
  pair<string, ll> tmp;
  tmp.first = vv[l].first + vv[r].first;
  tmp.second = ((vv[l].second % mod) * (vv[r].second % mod)) % mod;
  vv.push_back(tmp);
}

void remove (ll l, ll r) {
  if (l == -1 && r == -1) {
    return;
  }
  if (l == -1 && r != -1) {
    vv.erase(vv.begin() + r);
  }
  if (l != -1 && r == -1) {
    vv.erase(vv.begin() + l);
  }
  if (l != -1 && r != -1) {
    if (r > l) {
      ll tmp = l;
      l = r;
      r = tmp;
    }
    vv.erase(vv.begin() + l);
    vv.erase(vv.begin() + r);
  }
}

ll get_right_idx (char c) {
  for (ll i = 0; i < vv.size(); i++) {
    if (vv[i].first[0] == c) {
      return i;
    }
  }
  return -1;
}

ll get_left_idx (char c) {
  for (ll i = 0; i < vv.size(); i++) {
    if (vv[i].first[vv[i].first.size() - 1] == c) {
      return i;
    }
  }
  return -1;
}

ll fact (ll n) {
  ll ret = 1;
  for (ll i = n; i > 0; i--) {
    ret = ((ret % mod) * (i % mod)) % mod;
  }
  return ret;
}

string trim (string s) {
  if (s == "") {
    return s;
  }
  string t = "";
  t.push_back(s[0]);
  for (ll i = 0; i < s.size(); i++) {
    if (s[i] != t[t.size() - 1]) {
      t.push_back(s[i]);
    }
  }
  return t;
}

void clear_hash () {
  for (ll i = 0; i < hdim; i++) {
    hash[i] = 0;
  }
}

bool valid () {
  clear_hash();
  string s = v[0];

  hash[(ll)s[0]]++;

  for (ll i = 1; i < s.size(); i++) {
    if (s[i] != s[i - 1] && hash[(ll)s[i]] != 0) {
      return false;
    }
    hash[(ll)s[i]]++;
  }
  return true;
  clear_hash();
}

bool valid_pair (string a, string b) {
  assert(a.size() == 2 && b.size() == 2);
  if (a[0] == b[0] || a[1] == b[1]) {
    return false;
  } else {
    return true;
  }
}

void doit (ll cas) {
  cout << "Case #" << cas << ": ";
  clear_hash();

  ll N;
  cin >> N;
  cin.clear();
  cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

  string s;
  v.clear();
  for (ll i = 0; i < N; i++) {
    cin >> s;
    v.push_back(trim(s));
  }

  if (v.size() == 1) {
    if (valid()) cout << 1 << endl;
    else cout << 0 << endl;
    return;
  }

  // Get the singulars...
  ll it = 0;
  while (it < v.size()) {
    if (v[it].size() == 1) {
      hash[(ll)v[it][0]]++;
      v.erase(v.begin() + it);
    } else {
      it++;
    }
  }

  // Check the ones that are >= 3
  for (ll i = 0; i < v.size(); i++) {
    if (v[i].size() >= 3) {
      for (ll j = 1; j < v[i].size() - 1; j++) {
        for (ll k = i + 1; k < v.size(); k++) {
          for (ll l = 0; l < v[k].size(); l++) {
            if (v[i][j] == v[k][l]) {
              cout << 0 << endl;
              return;
            }
          }
        }
      }
    }
  }

  // Check the doubles...
  for (ll i = 0; i < v.size(); i++) {
    if (v[i].size() == 2) {
      for (ll j = i + 1; j < v.size(); j++) {
        if (v[j].size() == 2) {
          if (!valid_pair(v[i], v[j])) {
            cout << 0 << endl;
            return;
          }
        }
      }
    }
  }

  vv.clear();
  for (ll i = 0; i < v.size(); i++) {
    vv.push_back(make_pair(v[i], 1));
  }

  ll lidx, ridx;
  for (ll i = 0; i < hdim; i++) {
    if (hash[i] != 0) {
      lidx = get_left_idx((char)i);
      ridx = get_right_idx((char)i);

      pair<string, ll> ele;
      ele.first = string(1, (char)i);
      ele.second = fact(hash[i]);
      if (lidx != -1) {
        ele.first = vv[lidx].first + ele.first;
        ele.second = ((ele.second % mod) * (vv[lidx].second % mod)) % mod;
      }
      if (ridx != -1) {
        ele.first =  ele.first + vv[ridx].first;
        ele.second = ((ele.second % mod) * (vv[ridx].second % mod)) % mod;
      }
      vv.push_back(ele);
      remove(lidx, ridx);
    }
  }

  bool finished = false;
  while (!finished) {
    finished = true;
    for (ll i = 0; i < vv.size(); i++) {
      for (ll j = 0; j < vv.size(); j++) {
        if (vv[i].first[vv[i].first.size() - 1] == vv[j].first[0] && i != j) {
          merge(i, j);
          remove(i, j);
          finished = false;
          break;
        }
      }
      if (!finished) {
        break;
      }
    }
  }

  ll ans = 1;
  for (ll i = 0; i < vv.size(); i++) {
    ans = ((ans % mod) * (vv[i].second % mod)) % mod;
  }
  ans = ((ans % mod) * (fact(vv.size()) % mod)) % mod;
  v.clear();
  s = "";
  for (ll i = 0; i < vv.size(); i++) {
    s += vv[i].first;
    v.push_back(s);
  }
  if (!valid()) {
    cout << 0 << endl;
    return;
  }
  cout << ans << endl;
}

int main () {
  ll tcases;
  cin >> tcases;
  for (ll cas = 1; cas <= tcases; cas++) {
    doit(cas);
  }
  return 0;
}
