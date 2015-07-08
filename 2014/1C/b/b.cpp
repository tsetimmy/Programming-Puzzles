#include <iostream>
#include <limits>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;
#define mod 1000000007
#define hdim 500

ll hash[hdim];
vector<string> v;


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

bool valid_pair (string a, string b) {
  assert(a.size() == 2 && b.size() == 2);
  if (a[0] == b[0] || a[1] == b[1]) {
    return false;
  } else {
    return true;
  }
}

void doit (ll cas) {
  cout << cas << endl;
  clear_hash();

  ll N;
  cin >> N;
  cin.clear();
  cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

  string s;
  v.clear();
  for (ll i = 0; i < N; i++) {
    cin >> s;
    v.push_back(s);
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
      cout << "here is v[i]" << endl;
      cout << v[i] << endl;
      for (ll j = 1; j < v[i].size() - 1; j++) {
        for (ll k = i + 1; k < v.size(); k++) {
          for (ll l = 0; l < v[k].size(); l++) {
            if (v[i][j] == v[k][l]) {
              goto NOT_POSSIBLE;
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
            goto NOT_POSSIBLE;
          }
        }
      }
    }
  }

  vector<pair<string, ll> > vv;
  for (ll i = 0; i < hdim; i++) {
    if (hash[i] != 0) {
      vv.push_back(make_pair(string(1, (char)i), fact(hash[i])));
    }
  }


  cout << "might be possible" << endl;










  return;
  NOT_POSSIBLE:
  cout << 0 << endl;
}

int main () {
  ll tcases;
  cin >> tcases;

  for (ll cas = 1; cas <= tcases; cas++) {
    doit(cas);
  }

  return 0;
}
