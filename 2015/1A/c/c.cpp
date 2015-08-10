#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define inf 10000000
typedef long long ll;

struct pnt {
  ll x;
  ll y;
  ll best;
};

struct vec {
  ll x;
  ll y;
};

ll N;
vector<pnt> pnts;


ll cross (vec p, vec q) {
  return (p.x * q.y - p.y * q.x);
}

void doit (ll cas) {
  cout << "Case #" << cas << ":" << endl;
  cin >> N;
  pnts.clear();
  pnts = vector<pnt> (N);
  for (ll i = 0; i < N; i++) {
    cin >> pnts[i].x;
    cin >> pnts[i].y;
    pnts[i].best = inf;
  }

  if (N == 1) {
    cout << 0 << endl;
    return;
  }

  for (ll i = 0; i < N; i++) {
    for (ll j = 0; j < N; j++) {
      if (i != j) {
        ll c = 0;
        for (ll k = 0; k < N; k++) {
          if (k != i && k != j) {
            vec p;
            p.x = pnts[j].x - pnts[i].x;
            p.y = pnts[j].y - pnts[i].y;

            vec q;
            q.x = pnts[k].x - pnts[i].x;
            q.y = pnts[k].y - pnts[i].y;

            if (cross(p, q) > 0)
              c++;
          }
        }
        pnts[i].best = min(pnts[i].best, c);
      }
    }
  }

  for (ll i = 0; i < pnts.size(); i++) {
    cout << pnts[i].best << endl;
  }

}

int main () {
  ll tcases;
  cin >> tcases;
  for (ll cas = 0; cas < tcases; cas++)
    doit(cas + 1);
  return 0;
}

