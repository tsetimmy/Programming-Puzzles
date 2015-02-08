#include <iostream>
#include <cmath>
using namespace std;

long long N, PD, PG;
string ans;

#define EPSILON 0.000001


void solve (int tcase) {
  cin >> N >> PD >> PG;

  if (PG == 100 && PD != 100) {
    ans = "Broken";
    goto done;
  }
  if (PG == 100 && PD == 100) {
    ans = "Possible";
    goto done;
  }
  if (PG == 0 && PD > 0) {
    ans = "Broken";
    goto done;
  }
  if (PG == 0 && PD == 0) {
    ans = "Possible";
    goto done;
  }

  for (long long n = 1; n <= N; n++) {
    for (long long p = 1; p <= n; p++) {
      if (p*100 == n*PD) {
        ans = "Possible";
        goto done;
      }
    }
  }
  ans = "Broken";


  done:
  cout << "Case #" << tcase << ": " << ans << endl;

}

int main () {
  int T; cin >> T;
  for (int t = 1; t <= T; t++) {
    solve(t);
  }
  return 0;
}
