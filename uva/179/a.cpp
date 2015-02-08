#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;
#define maxn 260

string plain, cypher1, cypher2;
vector<ll> permute;

ll hash[maxn];

void recurse (string t1, string t2, string map, ll idx, bool& done) {
  if (idx == t1.size()) {
    if (good()) {
      done = true;
    }
    return;
  }

  for (ll i = 0; i < t2.size(); i++) {
    if (t1[idx] == t2[i] && map[i] == '0') {
      map[i] = '1';
      permute.push_back(i);
      recurse(t1, t2, map, idx + 1, done);
      if (done) {
        return;
      }
      map[i] = '0';
      permute.pop_back();
    }
  }


}

bool trans (ll num) {
  for (ll i = 0; i < maxn; i++) {
    hash[i] = 0;
  }

  for (ll i = 0; i < num; i++) {
    hash[(ll) plain[i]]++;
  }
  for (ll i = 0; i < num; i++) {
    hash[(ll) cypher1[i]]--;
  }
  for (ll i = 0; i < maxn; i++) {
    if (hash[i] != 0) {
      return false;
    }
  }

  string t1, t2, map;
  bool done = false;
  for (ll i = 0; i < num; i++) {
    t1.push_back(plain[i]);
    t2.push_back(cypher1[i]);
    map.push_back('0');
  }

  recurse(0, done);
  return done;


}

void doit () {
  if (plain == cypher1) {
    cout << cypher2 << endl;
    return;
  }

  if (plain.size() != cypher1.size()) {
    throw;
  }

  for (ll i = 1; i <= plain.size(); i++) {
    if (trans(i)) {
      cout << encrypt(i) << endl;
      return;
    }
  }
  cout << cypher2 << endl;

}

int main () {
  while (true) {
    cin >> plain;
    if (plain == "#") {
      break;
    }
    cin >> cypher1 >> cypher2;
    doit();
  }
  return 0;
}
