#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <cassert>
using namespace std;

typedef long long ll;
ll L, t, N, C;
ll total_distance;
ll acc_distance;
ll idx;
ll leftover;

vector<pair<ll,ll> > vec;

bool foo (pair<ll,ll> left, pair<ll,ll> right) {
  return left.first < right.first;
}

void solve (ll tcase) {
  vec.clear();
  cin >> L >> t >> N >> C;
  leftover = -1;

  ll value, count;
  for (ll i = 0; i < C; i++) {
    cin >> value;
    count = 0;
    vec.push_back(make_pair(value,count));
  }



  assert(C == vec.size());
  assert(t%2 == 0);

  total_distance = 0;
  idx = -1;
  for (ll i = 0; i < N; i++) {
    idx++;
    idx %= C;
    total_distance += vec[idx].first;
  }
  total_distance *= 2;

  bool start = false;
  acc_distance = 0;
  idx = -1;
  for (ll i = 0; i < N; i++) {
    idx++;
    idx %= C;

    if (start) {
      vec[idx].second++;
    }

    acc_distance += vec[idx].first;
    if (acc_distance >= t/2 && leftover == -1) {
      leftover = acc_distance-t/2;
      start = true;
    }
  }

  vec.push_back(make_pair(leftover, 1));
  assert(2*acc_distance == total_distance);





  sort(vec.begin(), vec.end(), foo);



  while (true) {
    if (L == 0) break;

    for (ll i = vec.size()-1; i >= 0; i--) {

      for (ll j = 0; j < vec[i].second; j++) {
        L--;
        total_distance -= vec[i].first;
        if (L == 0) break;
      }



//      if (L > 0 && vec[i].second > 0) {
//        L--;
//        vec[i].second--;
//        total_distance -= vec[i].first;
//      }
      if (L == 0) break;
    }
    break;
  }



  cout << "Case #" << tcase << ": " << total_distance << endl;








}

int main () {
  ll T; cin >> T;
  for (ll tt = 1; tt <= T; tt++) {
    solve(tt);
  }
  vec.clear();
  return 0;
}
