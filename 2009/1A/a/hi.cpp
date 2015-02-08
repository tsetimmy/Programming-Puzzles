#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <map>
#include <cmath>
using namespace std;

typedef long long ll;

#define maxn 3000000

ll happy_hash[9][maxn];
map<ll, ll> seen;
vector<pair<ll, ll> > bases;

vector<ll> convert_base (ll num, ll base) {

  vector<ll> vec; vec.clear();

  while (num != 0) {
    vec.push_back(num%base);
    num /= base;
  }
  std::reverse(vec.begin(), vec.end());
  return vec;
}


ll get_next (ll num, ll base) {
  ll ret = 0;
  vector<ll> vec = convert_base(num, base);
  for (ll i = 0; i < vec.size(); i++) {
    ret += vec[i]*vec[i];
  }
  return ret;
}

bool happy (ll num, ll base) {
  if (num == 1) return true;
  ll lead, lag;
  lead = num;
  lag = num;

  if (num < maxn) {
    if (happy_hash[base-2][num] != -1)
      return happy_hash[base-2][num]==1?true:false;
  }

  bool ans;
  while (true) {
    lead = get_next(lead, base);
    if (lead == 1) {
      ans = true;
      break;
    }
    if (lead == lag) {
      ans = false;
      break;
    }
    lead = get_next(lead, base);
    if (lead == 1) {
      ans = true;
      break;
    }
    if (lead == lag) {
      ans = false;
      break;
    }
    lag = get_next(lag, base);
    if (lead == lag) {
      ans = false;
      break;
    }
  }

  if (num < maxn) {
    happy_hash[base-2][num]=ans?1:0;
  }
  return ans;

}

void gen (ll curr_idx) {
  if (curr_idx == bases.size()) {
    ll base_count = 0;

    for (ll i = 0; i < bases.size(); i++) {
      if (bases[i].second == 1) {
        base_count++;
      }
    }

    if (base_count <= 1) {
      return;
    }

    ll id = 0;
    for (ll i = 0; i < bases.size(); i++) {
      if (bases[i].second == 1) {
        id += pow(2,i);
      }
    }
    cout << id << " ";

    bool found = false;
    for (ll i = 2; !found; i++) {
      found = true;
      for (ll j = 0; j < bases.size(); j++) {
        if (bases[j].second == 1) {
          if (!happy(i, bases[j].first)) {
            found = false;
            break;
          }
        }
      }
      if (found) {
        cout << i << endl;
      }
    }
  } else {
    for (ll i = 1; i >= 0; i--) {
      bases[curr_idx].second = i;
      gen(curr_idx+1);
    }
  }
}


int main () {

  for (ll i = 0; i < 9; i++) {
    for (ll j = 0; j < maxn; j++) {
      happy_hash[i][j] = -1;
    }
  }

  bases.clear();
  for (ll i = 2; i <= 10; i++) {
    bases.push_back(make_pair(i,0));
  }

  gen(0);

  return 0;
}
