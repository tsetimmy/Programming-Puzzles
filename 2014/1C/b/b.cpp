#include <iostream>
#include <vector>
#include <limits>
using namespace std;

typedef long long ll;
#define mod 1000000007
long long ans;
vector<pair<string, bool> > s;
vector<string> curr;

void print () {
  for (ll i = 0; i < curr.size(); i++) {
    cout << curr[i] << ",";
  }
  cout << endl;
}

void recurse () {
  ll done = true;
  for (ll i = 0; i < s.size(); i++) {
    if (s[i].second == false) {
      done = false;
      break;
    }
  }
  if (done) {
    ans++;
    print();
    return;
  }

  ll lidx = curr.size() - 1;
  ll slidx = curr[lidx].size() - 1;
  for (ll i = 0; i < s.size(); i++) {
    if (s[i].second == false && curr[lidx][slidx] == s[i].first[0]) {
      curr.push_back(s[i].first);
      s[i].second = true;
      recurse();
      curr.pop_back();
      s[i].second = false;
    }
  }
}

void doit (ll cas) {
  ll N;
  cin >> N;
  cin.clear();
  cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

  s.clear();
  curr.clear();
  string tmp;
  for (ll n = 0; n < N; n++) {
    cin >> tmp;
    s.push_back(make_pair(tmp, false));
  }

  ans = 0;
  for (ll i = 0; i < s.size(); i++) {
    curr.push_back(s[i].first);
    s[i].second = true;
    recurse();
    curr.pop_back();
    s[i].second = false;
  }
  cout << ans << endl;

}

int main () {
  ll tcases;
  cin >> tcases;
  for (ll cas = 1; cas <= tcases; cas++)  {
    doit(cas);
  }
  return 0;
}

