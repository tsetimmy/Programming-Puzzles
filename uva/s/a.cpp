#include <iostream>
#include <vector>
#include <limits>
#include <cmath>
#include <cassert>
using namespace std;

typedef long long ll;
#define dim 103


ll grid[dim][dim];
ll dp[dim][dim];
ll r, c;
vector<ll> ans;

ll fix (ll in) {
  if (in < 1) in = r;
  else if (in > r) in = 1;
  return in;
}

void print (ll row, ll col) {
  //cout << row << " ";
  ans.push_back(row);
  if (col == c) return;

  ll nr = std::numeric_limits<long long>::max();

  if (dp[row][col] == grid[row][col] + dp[fix(row - 1)][col + 1]) nr = min(nr, fix(row - 1));
  if (dp[row][col] == grid[row][col] + dp[fix(row + 1)][col + 1]) nr = min(nr, fix(row + 1));
  if (dp[row][col] == grid[row][col] + dp[row][col + 1]) nr = min(nr, row);

  print(nr, col + 1);

}


ll best (ll first, ll second, ll third) {
  ll ret = first;
  if (second < ret) ret = second;
  if (third < ret) ret = third;
  return ret;
}

ll recurse (ll row, ll col) {
  if (col == c) {
    dp[row][col] = grid[row][col];
    return grid[row][col];
  }

  ll& val = dp[row][col];
  if (val < std::numeric_limits<long long>::max()) {
    return val;
  }

  val = grid[row][col] + best(recurse(fix(row + 1), col + 1),recurse(fix(row - 1), col + 1), recurse(row, col + 1));
  return val;

}

void doit () {
  ans.clear();
  for (ll i = 0; i < dim; i++)
    for (ll j = 0; j < dim; j++)
      dp[i][j] = std::numeric_limits<long long>::max();

  for (ll i = 1; i <= r; i++) {
    dp[i][1] = recurse(i, 1);
  }

  ll lowest = std::numeric_limits<long long>::max();
  for (ll i = 1; i <= r; i++) {
    lowest = min(lowest, dp[i][1]);
  }


  for (ll i = 1; i <= r; i++) {
    if (lowest == dp[i][1]) {
      print(i, 1);
      for (ll it = 0; it < ans.size(); it++) {
        cout << ans[it];
        if (it == ans.size() - 1) cout << endl;
        else cout << " ";
      }
      cout << lowest << endl;
      break;
    }
  }

}

int main () {

  while (cin >> r) {
    cin >> c;
    for (ll i = 1; i <= r; i++)
      for (ll j = 1; j <= c; j++)
        cin >> grid[i][j];
    doit();
  }

  return 0;
}
