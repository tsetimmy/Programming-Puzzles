#include <iostream>
#include <vector>
#include <utility>
using namespace std;

#define dim 100
typedef long long ll;
pair<ll,ll> boxes[dim+1];
pair<ll,ll> toys [dim+1];
ll dp [dim+1][dim+1];
// first = amount
// second = typedef

ll maxx (ll left, ll right) {
  if (left > right) return left; return right;
}

ll minn (ll left, ll right) {
  if (left < right) return left; return right;
}



void solve (int tcase) {
  for (int i = 0; i < dim+1; i++) {
    boxes[i].first = 0; boxes[i].second = 0; 
    toys[i].first = 0; toys[i].second = 0; 
  }
  for (int i = 0; i < dim+1; i++) {
    for (int j = 0; j < dim+1; j++) {
      dp[i][j] = 0;
    }
  }
  int N, M;
  cin >> N >> M;
  for (int i = 1; i <= N; i++) {
    cin >> boxes[i].first >> boxes[i].second;
  }
  for (int i = 1; i <= M; i++) {
    cin >> toys[i].first >> toys[i].second;
  }

  int prev_box;
  int prev_toy;
  ll amount_box, amount_toy;
  ll state;
  bool done;
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= M; j++) {
      prev_box = i-1;
      prev_toy = j-1;
      amount_box = boxes[i].first;
      amount_toy = toys[j].first;
      done = false;
      if (boxes[i].second == toys[j].second) {
        while (true) {
          dp[i][j] = maxx(dp[i][j], dp[prev_box][prev_toy] + minn(amount_box, amount_toy));

          if (amount_box > amount_toy) {
            state = -1;
          } else if (amount_box < amount_toy) {
            state = 1;
          } else{
            state = 0;
          }

          if (state >= 0) {
            while (prev_box > 0 && boxes[prev_box].second != boxes[i].second) {
              prev_box--;
            }
            if (prev_box == 0) {
              done = true;
            } else {
              amount_box += boxes[prev_box].first;
              prev_box--;
            }
          }
          if (state <= 0) {
            while (prev_toy > 0 && toys[prev_toy].second != toys[j].second) {
              prev_toy--;
            }
            if (prev_toy == 0) {
              done = true;
            } else {
              amount_toy += toys[prev_toy].first;
              prev_toy--;
            }
          }


          if (done) {
            break;
          }
        }

      } else {
        dp[i][j] = maxx(dp[i-1][j], dp[i][j-1]);
      }
    }
  }

  cout << "Case #" << tcase << ": " << dp[N][M] << endl;
}

int main () {
  int T; cin >> T;
  for (int t = 1; t <= T; t++) {
    solve(t);
  }
  return 0;
}
