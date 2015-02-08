#include <iostream>
#include <vector>
#include <utility>
using namespace std;

#define dim 1000000
typedef long long ll;
ll K, n;
ll k [dim+1];
ll d [100];


void solve (int tcase) {
  cin >> K >> n;
  for (ll i = 0; i < n; i++) {
    cin >> d[i];
  }
  for (ll i = 1; i <= K; i++) {
    k[i] = -1;
  }

  ll it = 1;
  ll idx = -1;
  ll i;
  while (it != K + 1) {
    i = 0;
    while (i < it) {
      idx++;
      idx %= K;

      if (k[idx+1] == -1) {
        i++;
      }
    }
    k[idx+1] = it;
    it++;
  }

  cout << "Case #" << tcase << ": ";
  for (ll i = 0; i < n; i++) {
    cout << k[d[i]];
    if (i != n -1) cout << " ";
    else cout << endl;
  }


}

int main () {
  int T; cin >> T;
  for (int t = 1; t <= T; t++) {
    solve(t);
  }
  return 0;
}
