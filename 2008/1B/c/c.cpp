#include <iostream>
#include <vector>
using namespace std;

#define dim 5000
typedef long long ll;
ll K, n;
ll k [dim+1];
ll d [100];

vector<ll> vec;

void solve (int tcase) {
  cin >> K >> n;
  for (ll i = 0; i < n; i++) {
    cin >> d[i];
  }

  vec.clear();
  for (ll i = 1; i <= K; i++) {
    vec.push_back(i);
  }

  ll current_count, next_val;
  next_val = 1;
  current_count = 1;
  while (!vec.empty()) {
    if (next_val == current_count) {
      k[vec[0]] = next_val;
      next_val++;
      current_count = 1;
      vec.erase(vec.begin());
    } else {
      vec.push_back(vec[0]);
      vec.erase(vec.begin());
      current_count++;
    }
  }

  cout << "Case #" << tcase << ": ";
  for (ll i = 0; i < n; i++) {
    cout << k[d[i]];
    if (i != n -1) {
      cout << " ";
    } else {
      cout << endl;
    }
  }


}

int main () {
  int T; cin >> T;
  for (int t = 1; t <= T; t++) {
    solve(t);
  }
  return 0;
}
