#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>
using namespace std;

struct my {
  int idx;
  int org;
  double addition;
};

#define lmax 200
#define EPSILON 1e-7
int in[lmax];
int N;
vector<my> ans;
double sum, denom;

bool foo (my left, my right) {
  return left.org < right.org;
}

void solve (int tcase) {
  cin >> N;
  ans.clear();
  my temp;
  sum = 0.0;
  for (int i = 0; i < N; i++) {
    cin >> in[i];
    temp.idx = i;
    temp.org = in[i];
    temp.addition = (double)temp.org;
    sum += temp.addition;
    ans.push_back(temp);
  }
  
  denom = sum;
  sort(ans.begin(), ans.end(), foo);
  //for (int i = 0; i < ans.size(); i++) cout << ans[i].addition << " "; cout << endl;

  int idx;
  while (true) {
    if (sum <= 0.0 || abs(sum) <= EPSILON) break;
    idx = -1;
    for (int i = 1; i < N; i++) {
      if (ans[i].addition > ans[0].addition) {
        idx = i;
        break;
      }
    }
    if (idx == -1) {
      for (int i = 0; i < N; i++) {
        ans[i].addition += sum/(double)N;
      }
      sum = 0.0;
    } else {
      if ((double)idx*(ans[idx].addition-ans[0].addition) > sum) {
        for (int i = 0; i < idx; i++) {
          ans[i].addition += sum/(double)idx;
        }
        sum = 0.0;
      } else {
        sum -= (double)idx*(ans[idx].addition-ans[0].addition);
        for (int i = 0; i < idx; i++) {
          ans[i].addition = ans[idx].addition;
        }
      }
    }
  }
  cout << "Case #" << tcase << ": ";
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (i == ans[j].idx) {
        cout << 100*(ans[j].addition-(double)ans[j].org)/denom;
      }
    }
    if (i == N-1) cout << endl;
    else cout << " ";
  }
}

int main () {
  cout << std::fixed;
  cout << std::setprecision(9);
  int T; cin >> T;
  for (int t = 1; t <= T; t++) {
    solve(t);
  }
  return 0;
}
