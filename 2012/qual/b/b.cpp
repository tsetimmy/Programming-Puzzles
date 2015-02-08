#include <iostream>
#include <math.h>
#include <assert.h>
using namespace std;

struct triplet {
  int first;
  int second;
  int third;
};

int N, S, p;
triplet a[102];

void solve (int tcase) {
  cin >> N >> S >> p;

  int in;
  for (int n = 1; n <= N; n++) {
    cin >> in;
    if (in%3 == 0) {
      a[n].first = in/3;
      a[n].second = in/3;
      a[n].third = in/3;
    } else {
      int f, s, t, temp;
      temp = (int)(round(((double)in)/3));
      f = temp;
      s = temp;
      t = in-2*temp;
      if (temp > t) {
        f = t;
        s = temp;
        t = temp;
      }
      a[n].first = f;
      a[n].second = s;
      a[n].third = t;

    }
  }
  
  int ans = 0;
  for (int i = 1; i <= N; i++) {
    if (a[i].third >= p) {
      ans++;
    } else {
      if (S != 0 && a[i].second != 0 && a[i].second == a[i].third && a[i].third+1 >= p) {
        ans++;
        S--;
      }

    }
  }

  //if (S != 0) cout << "hmm" << endl;
  cout << "Case #" << tcase << ": " << ans << endl;




}


int main () {
  int T; cin >> T;
  for (int t = 1; t <= T; t++)
    solve(t);
  return 0;
}
