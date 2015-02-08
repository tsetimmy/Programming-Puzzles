// C++
#include <iostream>
#include <iomanip>
#include <sstream>
#include <algorithm>
#include <vector>
#include <limits>
#include <queue>
#include <utility> // pair
// C
#include <cstdlib> // atoi
#include <cmath>
#include <cassert>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
#define ullmax std::numeric_limits<unsigned long long>::max()
#define llmax std::numeric_limits<long long>::max()
#define intmax std::numeric_limits<int>::max()
//cin.clear();
//cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

ll N, K;
ll pos[16];

ll grid [16][16];

ll col_valid[16];
ll row_valid[16];

bool valid (ll row, ll col) {
  if (row_valid[row] == 0 || col_valid[col] == 0) {
    return false;
  }


  if (col-1 >= 0 && row-1 >=0 && grid[row-1][col-1] == 1)
    return false;
  if (col-1 >= 0 && row+1 <= N-1  && grid[row+1][col-1] == 1)
    return false;
  if (col+1 <= N-1 && row-1 >=0 && grid[row-1][col+1] == 1)
    return false;
  if (col+1 <= N-1 && row+1 <= N-1 && grid[row+1][col+1] == 1)
    return false;

  return true;
}

void recurse (ll r, ll& ans) {
  if (r == N) {
    ans++;
    return;
  }

  for (ll i = 0; i < N; i++) {
    if (valid(r, i)) {
      grid[r][i] = 1;
      col_valid[i] = 0;
      row_valid[r] = 0;
      recurse(r+1,ans);
      grid[r][i] = 0;
      col_valid[i] = 1;
      row_valid[r] = 1;
    }
  }
}

void solve (int tcase) {
  for (ll i = 0; i < 16; i++) {
    col_valid[i] = 1;
    row_valid[i] = 1;
  }
  for (ll i = 0; i < 16; i++)
    for (ll j = 0; j < 16; j++)
      grid[i][j] = 0;

  cin >> N >> K;
  for (ll i = 0; i < K; i++) {
    cin >> pos[i];
  }
  for (ll i = 0; i < K; i++) {
    grid[i][pos[i]] = 1;
    row_valid[i] = 0;
    col_valid[pos[i]] = 0;
  }


  ll ans = 0;
  recurse(K,ans);
  cout << ans<< endl;


}

int main () {
  int TTT; cin >> TTT;
  for (int ttt = 1; ttt <= TTT; ttt++) {
    solve(ttt);
  }
  return 0;
}
