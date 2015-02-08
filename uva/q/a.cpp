#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

vector<ll> up;
vector<ll> g; 


void doit (string s) {
  up.clear();
  vector<ll> t;
  ll num, len;


  for (ll i = 0; i < s.size(); i++) {
    t.clear();
    num = (ll)s[i];
    while(num != 0) {
      t.push_back(num%2);
      num /= 2;
    }
    std::reverse(t.begin(), t.end());
    up.insert(up.end(), t.begin(), t.end());
  }

  len = up.size() - 1;

  for (ll i = 0; i < 16; i++) {
    g.push_back(0):
  }

}

void go () {
  ll num = 34943;
  while (num != 0) {
    g.push_back(num%2);
    num /= 2;
  }
  std::reverse(g.begin(), g.end());
}

int main () {
  go();
  string s;
  while (true) {
    cin >> s;
    if (s == "#") break;
    doit(s);
  }
  return 0;
}
