#include <iostream>
#include <cmath>

using namespace std;

typedef long long ll;
#define INF 100000
ll N, M, K;
ll**** h;

ll sub (ll a, ll b) {
  return abs(a - b) + 1;
}

ll minimum (ll a, ll b) {
  if (a < b) {
    return a;
  } else {
    return b;
  }
}

bool outbounds (ll col) {
  return (col < 0 || col >= M);
}


ll recurse (ll cr, ll clc, ll crc, ll r) {
  if (r <= 0) {
    return 0;
  }
  if (cr >= N || outbounds(clc) || outbounds(crc)) {
    return INF;
  }
  if (h[cr][clc][crc][r]!= INF) {
    return h[cr][clc][crc][r];
  }

  ll best = INF;

  if ((r - sub(clc, crc)) <= 0) {
    best = sub(clc, crc);
  } else {
    for (ll i = -1; i <= 1; i++) {
      for (ll j = -1; j <= 1; j++) {
        best = minimum(best, 2 + recurse(cr + 1, clc + i, crc + j, r - sub(clc, crc)));
      }
    }
  }


  h[cr][clc][crc][r] = best;
  return best;




}

void doit (ll cas) {
  cin >> N >> M >> K;
  if (N == 1 || M == 1) {
    cout << "Case #" << cas << ": " << K << endl;
    return;
  }
  K++;

  h = new ll*** [N];
  for (ll i = 0; i < N; i++) {
    h[i] = new ll** [M];
    for (ll j = 0; j < M; j++) {
      h[i][j] = new ll* [M];
      for (ll k = 0; k < M; k++) {
        h[i][j][k] = new ll[K];
      }
    }
  }

  for (ll i = 0; i < N; i++) {
    for (ll j = 0; j < M; j++) {
      for (ll k = 0; k < M; k++) {
        for (ll l = 0; l < K; l++) {
          h[i][j][k][l] = INF;
        }
      }
    }
  }
  K--;


  ll ans = INF;
  ll remainder;
  for (ll i = 0; i < M; i++) {
    for (ll j = i; j < M; j++) {

      remainder = K - sub(i, j);
      for (ll k = -1; k <= 1; k++) {
        for (ll l = -1; l <= 1; l++) {
          ans = minimum(ans, recurse(1, i + k, j + l, remainder) + sub(i, j));
        }
      }
    }
  }
  cout << "Case #" << cas << ": " << ans << endl;














  for (ll i = 0; i < N; i++) {
    for (ll j = 0; j < M; j++) {
      for (ll k = 0; k < M; k++) {
        delete []h[i][j][k];
      }
      delete []h[i][j];
    }
    delete []h[i];
  }
  delete []h;






}

int main () {
  ll tcases;
  cin >> tcases;
  for (ll cas = 1; cas <= tcases; cas++) {
    doit(cas);
  }
  return 0;
}
