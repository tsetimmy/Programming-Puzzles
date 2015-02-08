#include <iostream>
#include <utility>
#include <vector>
#include <cmath>
#include <cassert>
using namespace std;

typedef long long ll;

struct my {
  ll first;
  ll second;
  ll third;
};

// amount, type
vector<pair<ll,ll> > a;
vector<pair<ll,ll> > b;
//ll hash[100][100];
vector<my> hash;
ll N, M;

ll get (ll boxAmount, ll toyAmount) {
  if (hash.empty()) return -1;

  for (int i = 0; i < hash.size(); i++) {
    if (hash[i].first == boxAmount && hash[i].second == toyAmount) {
      return hash[i].third;
    }
  }

  return -1;
}

ll doit (ll n, ll m, ll boxAmount, ll toyAmount) {
  if (n == N || m == M) {
    return 0;
  }

  ll amount = get(boxAmount, toyAmount);
  if (amount != -1) return amount;
  if (a[n].second == b[m].second) {
    if (a[n].first == b[m].first) {
      boxAmount -= a[n].first;
      toyAmount -= a[n].first;
      amount = a[n].first + doit(n+1, m+1, boxAmount, toyAmount);
      boxAmount += a[n].first;
      toyAmount += a[n].first;
    } else if (a[n].first > b[m].first) {
      boxAmount -= b[m].first;
      toyAmount -= b[m].first;
      a[n].first -= b[m].first;
      amount = b[m].first + doit(n, m+1, boxAmount, toyAmount);
      a[n].first += b[m].first;
      boxAmount += b[m].first;
      toyAmount += b[m].first;
    } else if (a[n].first < b[m].first) {
      boxAmount -= a[n].first;
      toyAmount -= a[n].first;
      b[m].first -= a[n].first;
      amount = a[n].first + doit(n+1, m, boxAmount, toyAmount);
      b[m].first += a[n].first;
      boxAmount += a[n].first;
      toyAmount += a[n].first;
    } else {
      assert(false);
    }
  } else {
    amount = max(doit(n+1, m, boxAmount-a[n].first*a[n].second, toyAmount), doit(n, m+1, boxAmount, toyAmount-b[m].first*b[m].second));
  }
  //val = amount;
  //return val;

  my temp;
  temp.first = boxAmount;
  temp.second = toyAmount;
  temp.third = amount;
  hash.push_back(temp);

  return amount;
}

void solve (int tcase) {
//  for (int i = 0; i < 100; i++) {
//    for (int j = 0; j < 100; j++) {
//      hash[i][j] = -1;
//    }
//  }
  hash.clear();
  a.clear();
  b.clear();
  cin >> N >> M;
  ll first, second;
  ll boxAmount, toyAmount;
  boxAmount = 0;
  toyAmount = 0;

  for (ll n = 0; n < N; n++) {
    cin >> first >> second;
    boxAmount += first*second;
    a.push_back(make_pair(first, second));
  }
  for (ll m = 0; m < M; m++) {
    cin >> first >> second;
    toyAmount += first*second;
    b.push_back(make_pair(first, second));
  }


  cout << "Case #" << tcase << ": " << doit(0,0,boxAmount,toyAmount) << endl;
}

int main () {
  int T; cin >> T;
  for (int t = 1; t <= T; t++) {
    solve(t);
  }
  return 0;
}
