#include <iostream>
#include <cmath>
using namespace std;
typedef long long ll;
#define mod 1000000007

ll dx[2]={-1,1};
ll dy[2]={-1,1};
ll N, K, pos[16], board [16][16], col_taken[16], row_taken[16], DP[18][131071][16];

bool out (ll row, ll col) {
  return (row < 0 || row > N || col < 0 || col > N);
}

bool valid (ll row, ll col) {
  if (row_taken[row] == 0 || col_taken[col] == 0) {
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

ll recurse (ll r, ll stat) {
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
    if (valid(r, i)) {
      board[r][i] = 1;
      col_taken[i] = 0;
      row_taken[r] = 0;
      ret += recurse(r+1,stat+pow(2,i))%mod;
      board[r][i] = 0;
      col_taken[i] = 1;
      row_taken[r] = 1;
    }
  }

  if (r != 0 && prev != -1 && DP[r][stat][prev] == -1) {
    DP[r][stat][prev] = ret;
  }

  return ret;
}

void solve (int tcase) {
  for (ll i = 0; i < 18; i++) {
    for (ll j = 0; j < 131071; j++) {
      for (ll k = 0; k < 16; k++) {
        DP[i][j][k] = -1;
      }
    }
  }
  for (ll i = 0; i < 16; i++) {
    col_taken[i] = 1;
    row_taken[i] = 1;
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
    row_taken[i] = 0;
    col_taken[pos[i]] = 0;
    stat += pow(2,pos[i]);
  }

  ll ans = recurse(K,stat);
  cout << ans%mod << endl;
}

int main () {
  int cases; cin >> cases;
  for (int cas = 1; cas <= cases; cas++) {
    solve(cas);
  }
  return 0;
}
