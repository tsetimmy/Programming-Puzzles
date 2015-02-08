#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
#define dim 10000


struct triplet {
  ll L;
  ll R;
  ll H;
};

vector<triplet> in;
ll ans[dim+5];

bool byL (triplet left, triplet right) {
  return left.L < right.L;
}

void doit () {
  sort(in.begin(), in.end(), byL);
  for (ll i = 0; i < dim; i++) {
    ans[i] = 0;
  }

  for (ll i = 0; i < in.size(); i++) {
    for (ll j = in[i].L; j < in[i].R; j++) {
      ans[j] = max(ans[j], in[i].H);
    }
  }

  ll c = 0;
  ll idx = 0;

  ll m = -1;
  for (ll i = 0; i < in.size(); i++) {
    m = max(m, in[i].R);
  }

  while (idx < m) {
    if (idx == 0) {
      if (ans[idx] != 0) {
        cout << idx << " " << ans[idx] << " ";
      }
      idx++;
    }
    if (ans[idx] == ans[idx-1]) {
      idx++;
    } else {
      cout << idx << " " <<  ans[idx] << " ";
      idx++;
    }
  }

  cout << idx << " 0" << endl;
  //cout << idx << " 0";



//  cout << "here" << endl;
//  for (ll i = 0; i < m; i++) {
//    cout << ans[i] << " ";
//  }
//  cout << endl;







}


int main () {
  in.clear();
  ll L, R, H;
  while (cin >> L >> H >> R) {
    triplet t;
    t.L = L;
    t.R = R;
    t.H = H;
    in.push_back(t);
  }
  doit();
  return 0;
}
