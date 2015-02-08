#include <iostream>
#include <cassert>
#include <vector>
#include <utility>
using namespace std;

typedef long long ll;

ll n, A, B, C, D, x, y, M;
vector<pair<ll,ll> > coor;



void solve (int tcase) {
  cin >> n>> A>> B>> C>> D>> x>> y>> M;

  coor.clear();

  coor.push_back(make_pair(x, y));
  for (ll i = 1; i <= n-1; i++) {
    x = (A * x + B) % M;
    y = (C * y + D) % M;
    coor.push_back(make_pair(x, y));
  }


  ll ans = 0;
  for (ll i = 0; i < coor.size(); i++) {
    for (ll j = i+1; j < coor.size(); j++) {
      for (ll k = j+1; k < coor.size(); k++) {
        //for (ll l = 0; l < coor.size(); l++) {

          if (
               (coor[i].first+coor[j].first+coor[k].first)%3==0 &&
               (coor[i].second+coor[j].second+coor[k].second)%3 == 0
              //i != j &&
              //i != k &&
              //i != l &&
              //j != k
              //j != l &&
              //k != l
              ) {
            ans++;
          }



        //}
      }
    }
  }

  //assert(ans%3==0);

  cout << "Case #" << tcase << ": " << ans << endl;
}

int main () {
  int Tcase; cin >> Tcase;
  for (int tc = 1; tc <= Tcase; tc++) {
    solve(tc);
  }
  return 0;
}
