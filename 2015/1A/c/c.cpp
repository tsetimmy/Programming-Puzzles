// Works for both small and large inputs.
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

long double ep = 1e-15;

void doit (int cas) {
  int n;
  cin >> n;
  int x[n], y[n];

  for (int i = 0; i < n; i++) {
    cin >> x[i] >> y[i];
  }
  cout << "Case #" << cas << ":" << endl;

  for (int i = 0; i < n; i++) {
    long double a[2 * n];
    int ans = 30000, an = 0;
    for (int j = 0; j < n; j++) {
      if (i != j) {
        a[an] = atan2l(y[j] - y[i], x[j] - x[i]);
        an++;
      }
    }
    sort(a, a + an);
    for (int j = 0; j < an; j++) {
      a[an + j] = a[j] + 2 * M_PI;
    }

    int l = 0, r = 0;
    for (int j = 0; j < n; j++) {
      while (l + 1 < 2 * an && a[l] - a[j] < ep)
        l++;
      while (r < 2 * an && a[r] - a[j] < M_PI - ep)
        r++;
      ans = min(ans, r - l);
    }
    cout << ans << endl;
  }
}

int main () {
  int tcases;
  cin >> tcases;
  for (int cas = 0; cas < tcases; cas++)
    doit(cas + 1);
  return 0;
}
