#include <iostream>
#include <cmath>
using namespace std;

#define maxn 65535
#define mod 1000000007 
typedef long long ll;
ll dx[2]={-1,1}, dy[2]={-1,1};
ll N, K;
ll pos[16], col_ok[16], row_ok[16];
ll DP[18][maxn+5][16], board[16][16];

bool out (ll row, ll col) {
  return (row < 0 || row >= N || col < 0 || col >= N);
}

bool ok (ll row, ll col) {
  if (row_ok[row] == 0 || col_ok[col] == 0) {
    return false;
  }
  for (ll i = 0; i < 2; i++) {
    for (ll j = 0; j < 2;j ++) {
      if (!out(row+dx[i], col+dy[j]) && board[row+dx[i]][col+dy[j]]==1) {
        return false;
      }
    }
  }
  return true;
}

ll doit (ll r, ll stat) {
  if (r == N) {
    return 1;
  }

  ll prev = -1;
  if (r != 0) {
    for (ll i = 0; i < N; i++) {
      if (board[r-1][i] == 1) {
        prev = i;
        break;
      }
    }

    if (DP[r][stat][prev] != -1) {
      return DP[r][stat][prev];
    }
  }

  ll ret = 0;
  for (ll i = 0; i < N; i++) {
    if (ok(r, i)) {
      board[r][i] = 1;
      row_ok[r] = 0;
      col_ok[i] = 0;
      ret += doit(r+1,stat+pow(2,i))%mod;
      board[r][i] = 0;
      row_ok[r] = 1;
      col_ok[i] = 1;
    }
  }

  if (r != 0 && prev != -1 && DP[r][stat][prev] == -1) {
    DP[r][stat][prev] = ret;
  }
  return ret;
}

int main () {
  int cases; cin >> cases;
  for (int cas = 1; cas <= cases; cas++) {

    for (ll i = 0; i < 18; i++) {
      for (ll j = 0; j < maxn+5; j++) {
        for (ll k = 0; k < 16; k++) {
          DP[i][j][k] = -1;
        }
      }
    }

    for (ll i = 0; i < 16; i++) {
      col_ok[i] = 1;
      row_ok[i] = 1;
    }
    for (ll i = 0; i < 16; i++)
      for (ll j = 0; j < 16; j++)
        board[i][j] = 0;

    cin >> N >> K;
    for (ll i = 0; i < K; i++) {
      cin >> pos[i];
    }

    ll stat = 0;
    for (ll i = 0; i < K; i++) {
      board[i][pos[i]] = 1;
      row_ok[i] = 0;
      col_ok[pos[i]] = 0;
      stat += pow(2,pos[i]);
    }

    ll ans = doit(K,stat);
    cout << ans%mod << endl;

  }
  return 0;
}
